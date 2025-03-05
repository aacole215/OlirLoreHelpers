#include <iostream>
#include <string>
#include <vector>

#include "measurement_converter.h"

using measurement_converter::ConversionType;
using measurement_converter::MeasurementConverter;
using measurement_converter::SystemType;

SystemType GetSystemType(std::string prompt,
                         const std::vector<std::string>& time_systems) {
  int input = -1;

  do {
    std::cout << prompt;

    if (!(std::cin >> input)) {
      // Bad input case.
      std::cout << "Invalid input.\n";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      continue;
    }
    // Input is at least a valid int...

    if (input < 1 || input > time_systems.size()) {
      // Another bad input case.
      std::cout << "Invalid input.\n";
      continue;
    }

    // Good input!
    --input;  // Adjust for 0-indexing.
    auto sys_type = SystemType(input);
    std::cout << "You Chose: " << time_systems[input] << "\n";
    return sys_type;
  } while (true);
}

int main() {
  std::vector<std::string> time_systems = {
      "AS | Aeon Soterias", "EK | Etous tou Kyriou", "E  | Extranor"};

  int i = 1;
  for (const std::string& time_system : time_systems) {
    std::cout << i << ": " << time_system << "\n";
    ++i;
  }

  SystemType convert_from = GetSystemType(
      "Enter a time system you'd like to use to convert from (1-3):\n",
      time_systems);
  SystemType convert_to = GetSystemType(
      "Enter the time system you'd like to convert to (1-3):\n", time_systems);

  if (convert_from == convert_to) {
    std::cout << "There's no reason to do that, silly! Try again later.\n";
    return 0;
  }

  std::cout << "Enter the year you'd like to convert: ";
  int year;
  // I'm not doing validation here cry more
  std::cin >> year;

  // Yikes.
  ConversionType conversion_type;
  if (convert_from == SystemType::AS) {
    if (convert_to == SystemType::EK) {
      conversion_type = ConversionType::AS_TO_EK;
    } else {  // convert_to == E
      conversion_type = ConversionType::AS_TO_E;
    }
  } else if (convert_from == SystemType::EK) {
    if (convert_to == SystemType::AS) {
      conversion_type = ConversionType::EK_TO_AS;
    } else {  // convert_to == E
      conversion_type = ConversionType::EK_TO_E;
    }
  } else {  // convert_From == E
    if (convert_to == SystemType::AS) {
      conversion_type = ConversionType::E_TO_AS;
    } else {  // convert_to == EK
      conversion_type = ConversionType::E_TO_EK;
    }
  }

  auto year_converter = MeasurementConverter::CreateDefault();
  int converted_year = year_converter->ConvertYear(
      conversion_type, year);  // There's some cases missing here where the
                               // converted year doesn't actually exist but idc.
  std::cout << "The converted year is: " << converted_year << "\n";

  return 0;
}
