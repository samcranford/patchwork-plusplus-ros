#include <chrono>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/msg/point_field.hpp"

#include "patchworkpp/patchworkpp.hpp"

using namespace std::chrono_literals;

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PatchWorkpp>());
    rclcpp::shutdown();
    return 0;
}