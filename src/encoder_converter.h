//
// Created by tao on 7/21/21.
//

#ifndef SRC_ENCODER_CONVERTER_H
#define SRC_ENCODER_CONVERTER_H

#include "converter.h"

namespace kaist2bag {

class EncoderConverter : public Converter {
public:
    EncoderConverter(const std::string& dataset_dir, const std::string& save_dir, const std::string& topic);
    virtual ~EncoderConverter() = default;

    int Convert() override;

    std::string default_data_file = "sensor_data/encoder.csv";

private:
    std::string topic_;
    std::string bag_name_;
};




} // namespace kaist2bag

#endif //SRC_ENCODER_CONVERTER_H
