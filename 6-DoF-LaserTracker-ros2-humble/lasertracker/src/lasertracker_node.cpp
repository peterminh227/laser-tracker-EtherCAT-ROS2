// #include <boost/asio.hpp>
// #include <rclcpp/rclcpp.hpp>
// #include <geometry_msgs/msg/pose_stamped.hpp>
// #include "lasertracker/LaserTrackerMeasurement.hpp"

// using boost::asio::ip::udp;

// class LaserTrackerNode : public rclcpp::Node {
// public:
//     LaserTrackerNode(int port)
//         : Node("laser_tracker_node"),
//           socket_(io_context_, udp::endpoint(boost::asio::ip::make_address("0.0.0.0"), port)) {
//         publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/lasertracker", 10);
//         start_receiving();
//         RCLCPP_INFO(this->get_logger(), "LaserTrackerNode initialized and listening on port %d", port);
//     }

// private:
//     void start_receiving() {
//         RCLCPP_INFO(this->get_logger(), "LaserTrackerNode start receiving");
//         socket_.async_receive_from(
//             boost::asio::buffer(buffer_), sender_endpoint_,
//             [this](const boost::system::error_code &error, std::size_t bytes_received) {
//                 if (error) {
//                     RCLCPP_ERROR(this->get_logger(), "Error receiving UDP data: %s", error.message().c_str());
//                     return;
//                 }
                
//                 RCLCPP_INFO(this->get_logger(), "LaserTrackerNode receiving");
//                 if (bytes_received > 0) {
//                     LaserTrackerMeasurement measurement;
//                     std::memcpy(&measurement, buffer_.data(), sizeof(LaserTrackerMeasurement));

//                     // Create and populate the PoseStamped message
//                     auto msg = geometry_msgs::msg::PoseStamped();
//                     msg.header.stamp = this->get_clock()->now();
//                     msg.header.frame_id = "laser_tracker_frame"; 

//                     msg.pose.position.x = measurement.get_x();  
//                     msg.pose.position.y = measurement.get_y();  
//                     msg.pose.position.z = measurement.get_z();  

//                     msg.pose.orientation.x = measurement.quaternion[1];
//                     msg.pose.orientation.y = measurement.quaternion[2];
//                     msg.pose.orientation.z = measurement.quaternion[3];
//                     msg.pose.orientation.w = measurement.quaternion[0];

//                     // Publish the message
//                     publisher_->publish(msg);

//                     RCLCPP_INFO(this->get_logger(), "Received measurement from %s:%d", 
//                                  sender_endpoint_.address().to_string().c_str(), sender_endpoint_.port());
//                 }

//                 start_receiving();  // Start listening for the next packet
//             });
//     }

//     boost::asio::io_context io_context_;
//     udp::socket socket_;
//     udp::endpoint sender_endpoint_;
//     std::array<char, sizeof(LaserTrackerMeasurement)> buffer_;
//     rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
// };

// int main(int argc, char *argv[]) {
//     rclcpp::init(argc, argv);
//     const int port = 10000;  // Set your port here

//     auto node = std::make_shared<LaserTrackerNode>(port);
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }





///// synchronous version



#include <boost/asio.hpp>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include "lasertracker/LaserTrackerMeasurement.hpp"

using boost::asio::ip::udp;

class LaserTrackerNode : public rclcpp::Node {
public:
    LaserTrackerNode(int port)
        : Node("laser_tracker_node"),
          socket_(io_context_, udp::endpoint(boost::asio::ip::make_address("0.0.0.0"), port)) {
        publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/lasertracker", 10);
        RCLCPP_INFO(this->get_logger(), "LaserTrackerNode initialized and listening on port %d", port);
    }

    void spin() {
        while (rclcpp::ok()) {
            // Clear the buffer before receiving
            buffer_.fill(0);

            // Synchronously receive data
            boost::system::error_code error;
            std::size_t bytes_received = socket_.receive_from(boost::asio::buffer(buffer_), sender_endpoint_, 0, error);

            if (error) {
                RCLCPP_ERROR(this->get_logger(), "Error receiving UDP data: %s", error.message().c_str());
                continue;
            }

            // RCLCPP_INFO(this->get_logger(), "LaserTrackerNode receiving data...");

            if (bytes_received > 0) {
                LaserTrackerMeasurement measurement;
                std::memcpy(&measurement, buffer_.data(), sizeof(LaserTrackerMeasurement));

                // Create and populate the PoseStamped message
                auto msg = geometry_msgs::msg::PoseStamped();
                msg.header.stamp = this->get_clock()->now();
                msg.header.frame_id = "laser_tracker_frame";

                msg.pose.position.x = measurement.get_x();  
                msg.pose.position.y = measurement.get_y();  
                msg.pose.position.z = measurement.get_z();  

                msg.pose.orientation.x = measurement.quaternion[1];
                msg.pose.orientation.y = measurement.quaternion[2];
                msg.pose.orientation.z = measurement.quaternion[3];
                msg.pose.orientation.w = measurement.quaternion[0];

                // Publish the message
                publisher_->publish(msg);

                // RCLCPP_INFO(this->get_logger(), "Received measurement from %s:%d", 
                //              sender_endpoint_.address().to_string().c_str(), sender_endpoint_.port());
            }

            // Process any ROS events
            rclcpp::spin_some(this->get_node_base_interface());
        }
    }

private:
    boost::asio::io_context io_context_;
    udp::socket socket_;
    udp::endpoint sender_endpoint_;
    std::array<char, sizeof(LaserTrackerMeasurement)> buffer_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    const int port = 10000;  // Set your port here

    auto node = std::make_shared<LaserTrackerNode>(port);
    node->spin();  // Use the synchronous spin method
    rclcpp::shutdown();
    return 0;
}
