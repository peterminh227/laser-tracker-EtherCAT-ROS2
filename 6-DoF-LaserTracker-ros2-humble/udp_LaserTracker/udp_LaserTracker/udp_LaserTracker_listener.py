import socket
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import struct
import math

class UDPLaserTrackerListener(Node):
    def __init__(self, port):
        super().__init__('udp_laser_tracker_listener')

        # Create a publisher to publish the parsed LaserTracker data
        self.publisher_ = self.create_publisher(PoseStamped, 'laser_tracker_pose', 10)

        # Create a UDP socket
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(('', port))  # Bind to all interfaces

        self.get_logger().info(f'Listening for UDP messages on port {port}...')

        # Start a timer to run the receive loop
        self.timer = self.create_timer(0.01, self.receive_data)  # Call receive_data every 10 ms/100Hz

    def receive_data(self):
        try:
            # Receive message and address
            data, addr = self.sock.recvfrom(1024)  # Buffer size is 1024 bytes
            self.get_logger().info(f'Received message from {addr}')

            # Decode the data (expecting a total of 7 doubles)
            if len(data) >= 8 * 7:  # Check if there's enough data for 7 doubles
                # this should be match with order from LaserTrackerrMeasurement.h  in Beckhoff project 
                angle_hz, angle_vt, distance, *quaternion = self.unpack_data(data)

                # Convert to Cartesian coordinates
                x = distance * math.cos(angle_vt) * math.cos(angle_hz)
                y = distance * math.cos(angle_vt) * math.sin(angle_hz)
                z = distance * math.sin(angle_vt)


 
                # Prepare the PoseStamped message
                msg = PoseStamped()
                msg.header.stamp = self.get_clock().now().to_msg()  # Convert to ROS Time message
                msg.header.frame_id = "laser_tracker_frame"

                msg.pose.position.x = x
                msg.pose.position.y = y
                msg.pose.position.z = z

                msg.pose.orientation.x = quaternion[1]
                msg.pose.orientation.y = quaternion[2]
                msg.pose.orientation.z = quaternion[3]
                msg.pose.orientation.w = quaternion[0]

                # Publish the message
                self.publisher_.publish(msg)

                self.get_logger().info(f'Published pose: {msg}')

        except BlockingIOError:
            # No data received, continue
            pass

    def unpack_data(self, data):
        """Unpack the received bytes into doubles and return them."""
        # Expecting 7 doubles: angle_hz, angle_vt, distance, quaternion[0], quaternion[1], quaternion[2], quaternion[3]
        unpacked_data = struct.unpack('ddddddd', data[:8 * 7])  # 8 bytes per double
        return unpacked_data

def main(args=None):
    rclpy.init(args=args)
    port = 10000  # Change to your desired port
    udp_listener = UDPLaserTrackerListener(port)

    try:
        rclpy.spin(udp_listener)
    except KeyboardInterrupt:
        pass
    finally:
        udp_listener.sock.close()
        udp_listener.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
