//
// Created by tao on 7/21/21.
//

#include "encoder_converter.h"

#include <rosbag/bag.h>
#include <irp_sen_msgs/encoder.h>
#include <boost/filesystem.hpp>

namespace kaist2bag {


EncoderConverter::EncoderConverter(const std::string &dataset_dir, const std::string &save_dir,
                                   const std::string &topic)
                                   : Converter(dataset_dir, save_dir), topic_(topic) {
    bag_name_ = FilterSlash(topic_) + ".bag";
}

int EncoderConverter::Convert() {
    CheckAndCreateSaveDir();
    boost::filesystem::path bag_file = boost::filesystem::path(save_dir_) / bag_name_;
    rosbag::Bag bag(bag_file.string(), rosbag::bagmode::Write);
    ROS_INFO("saving %s", bag_file.c_str());

    const std::string data_file = dataset_dir_ + "/" + default_data_file;
    FILE* fp = fopen(data_file.c_str(), "r");
    irp_sen_msgs::encoder encoder_data;
    int64_t stamp, left_count, right_count;
    while (fscanf(fp, "%ld,%ld,%ld\n", &stamp, &left_count, &right_count) == 3) {
        encoder_data.header.stamp.fromNSec(stamp);
        encoder_data.header.frame_id = "encoder";
        encoder_data.left_count = left_count;
        encoder_data.right_count = right_count;

        bag.write(topic_, encoder_data.header.stamp, encoder_data);
    }
    bag.close();
    fclose(fp);
    ROS_INFO("done saving %s", bag_file.c_str());

    return 0;
}
} // namespace kaist2bag

