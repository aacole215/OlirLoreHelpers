#include "measurement_converter.h"

#include <iostream>
#include <memory>
#include <string>

namespace measurement_converter {

namespace {

constexpr int kAsToEkVal = 1011;
constexpr int kEToAsVal = 12878;
constexpr int kEToEkVal = 13889;

class MeasurementConverterImpl : public MeasurementConverter {
 public:
  MeasurementConverterImpl() = default;

  int ConvertYear(ConversionType conversion_type, int year) override {
    switch (conversion_type) {
      case AS_TO_EK:
        return ConvertAsToEk(year);
      case AS_TO_E:
        return ConvertAsToE(year);
      case EK_TO_AS:
        return ConvertEkToAs(year);
      case EK_TO_E:
        return ConvertEkToE(year);
      case E_TO_AS:
        return ConvertEToAs(year);
      case E_TO_EK:
        return ConvertEToEk(year);
      default:
        std::cout << "nah bro you done goofed\n";
        return -1;
    }
  }

 private:
  int ConvertAsToEk(int as_year) override { return as_year - kAsToEkVal; }

  int ConvertAsToE(int as_year) override { return as_year + kEToAsVal; }

  int ConvertEkToAs(int ek_year) override { return ek_year + kAsToEkVal; }

  int ConvertEkToE(int ek_year) override { return ek_year + kEToEkVal; }

  int ConvertEToAs(int e_year) override { return e_year - kEToAsVal; }

  int ConvertEToEk(int e_year) override { return e_year - kEToEkVal; }
};
}  // namespace

std::unique_ptr<MeasurementConverter> MeasurementConverter::CreateDefault() {
  return std::make_unique<MeasurementConverterImpl>();
}

}  //  namespace measurement_converter
