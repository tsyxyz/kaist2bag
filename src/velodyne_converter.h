//
// Created by tao on 7/25/21.
//

#ifndef SRC_VELODYNE_CONVERTER_H
#define SRC_VELODYNE_CONVERTER_H
#include <string>
#include "converter.h"

namespace kaist2bag {

class VelodyneConverter : public Converter {
public:
    VelodyneConverter(const std::string& dataset_dir, const std::string& save_dir,
                      const std::string& left_topic, const std::string& right_topic);
    virtual ~VelodyneConverter() = default;

    int Convert() override;

    std::string default_left_stamp_file = "sensor_data/VLP_left_stamp.csv";
    std::string default_left_data_dir = "sensor_data/VLP_left";
    std::string default_right_stamp_file = "sensor_data/VLP_right_stamp.csv";
    std::string default_right_data_dir = "sensor_data/VLP_right";

private:
    std::string left_topic_;
    std::string left_bag_name_;
    std::string right_topic_;
    std::string right_bag_name_;

    void Convert(const std::string& stamp_file, const std::string& data_dir,
                 const std::string& bag_file, const std::string& topic,
                 const std::string& frame_id);
};


} // namespace kaist2bag
#endif //SRC_VELODYNE_CONVERTER_H
