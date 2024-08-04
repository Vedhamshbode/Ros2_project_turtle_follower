#include "rclcpp/rclcpp.hpp"
#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

using namespace std;

class Sub1Node : public rclcpp::Node
{
public:
    Sub1Node() : Node("sub1_node")
    {
        subscriber1=this->create_subscription<turtlesim::msg::Pose>(
                                        "/turtle1/pose",
                                        10,
                                        bind(&Sub1Node::sub1_callback, 
                                        this, 
                                        placeholders::_1));
        subscriber2=this->create_subscription<turtlesim::msg::Pose>(
                                        "/turtle2/pose",
                                        10,
                                        bind(&Sub1Node::sub2_callback, 
                                        this, 
                                        placeholders::_1));
        publisher=this->create_publisher<geometry_msgs::msg::Twist>(
                                        "/turtle2/cmd_vel", 
                                        10);
        RCLCPP_INFO(this->get_logger(), "The sub1 node has started");
        timer1=this->create_wall_timer(chrono::milliseconds(1500), bind(&Sub1Node::callback4, this));
        timer2=this->create_wall_timer(chrono::milliseconds(3000), bind(&Sub1Node::callback2, this));
    }
private:
    void sub1_callback(const turtlesim::msg::Pose::SharedPtr data1){
        x1=data1->x;
        y1=data1->y;
        theta1=data1->theta;
        RCLCPP_INFO(this->get_logger(), "%f, %f, %f",x1, y1, theta1);
    }
    void sub2_callback(const turtlesim::msg::Pose::SharedPtr data2){
        x2=data2->x;
        y2=data2->y;
        theta2=data2->theta;
        RCLCPP_INFO(this->get_logger(), "%f, %f, %f",x2, y2, theta2);
        
    }
    void callback2(){
        auto data3=geometry_msgs::msg::Twist();
        d=pow((pow((y2-y1),2)+pow((x2-x1),2)),0.5);
        RCLCPP_INFO(this->get_logger(), "%f", d);
        if (d>0.05){
            data3.linear.x=d;
            data3.linear.y=0;
            data3.linear.z=0;
            data3.angular.x=0;
            data3.angular.y=0;
            data3.angular.z=0;
            publisher->publish(data3);
    }}
    void callback4(){
        auto data4=geometry_msgs::msg::Twist();
        a=(y2-y1)/(x2-x1);
        slope=atan(a);
        if (x2>=x1){
            // if ((slope-theta2)>=3.14){
            //     delt=(slope-theta2)-6.28;
            // }
            // else if ((slope-theta2)<=-3.14)
            // {
            //     delt=6.28+(slope-theta2);
            // }
            // else
            // {
            //     delt=theta2-slope;
            // }
            delt=-(3.14-(slope-theta2));
        }
        else{
            if ((slope-theta2)>=3.14){
                delt=(slope-theta2)-6.28;
            }
            else if ((slope-theta2)<=-3.14)
            {
                delt=6.28+(slope-theta2);
            }
            else
            {
                delt=slope-theta2;
            }
        }
        RCLCPP_INFO(this->get_logger(), "%f", delt);
        data4.linear.x=0;
        data4.linear.y=0;
        data4.linear.z=0;
        data4.angular.x=0;
        data4.angular.y=0;
        data4.angular.z=delt;
        publisher->publish(data4);
    }
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber1;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber2;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
    rclcpp::TimerBase::SharedPtr timer1, timer2;
    double x1,y1, theta1,x2,y2,theta2, d, a, delt, slope;
    
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = make_shared<Sub1Node>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}