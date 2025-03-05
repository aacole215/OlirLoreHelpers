#ifndef MEASUREMENT_CONVERTER_H
#define MEASUREMENT_CONVERTER_H

#include <memory>
#include <string>

namespace measurement_converter {

enum SystemType { AS, EK, E };

enum ConversionType {
  AS_TO_EK,
  AS_TO_E,
  EK_TO_AS,
  EK_TO_E,
  E_TO_AS,
  E_TO_EK,
};

// Class to facilitate conversions between different measurements of time
// (years).
class MeasurementConverter {
 public:
  virtual ~MeasurementConverter() = default;

  static std::unique_ptr<MeasurementConverter> CreateDefault();

  // Performs & returns the proper conversion based on the conversion_type.
  virtual int ConvertYear(ConversionType conversion_type, int year) = 0;

 private:
  virtual int ConvertAsToEk(int as_year) = 0;

  virtual int ConvertAsToE(int as_year) = 0;

  virtual int ConvertEkToAs(int ek_year) = 0;

  virtual int ConvertEkToE(int ek_year) = 0;

  virtual int ConvertEToAs(int e_year) = 0;

  virtual int ConvertEToEk(int e_year) = 0;
};

}  // namespace measurement_converter

#endif  // MEASUREMENT_CONVERTER_H
