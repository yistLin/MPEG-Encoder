#include "util.h"

Util::Util(const int argc, const char *argv[]) {
  this->logger = Log("Util");

  std::map<std::string, std::string> options{{"verbose", "false"},
                                             {"size", "0x0"},
                                             {"input_file", "snoopy.avi"},
                                             {"output_file", "snoopy.264"}};

  // get arguments from command line
  for (int i = 1; i < argc; i++) {
    std::string key, value;
    std::istringstream argument{argv[i]};

    if (argument.peek() == '-') {
      argument.get();
      if (argument.peek() == '-') {
        argument.get();
        std::getline(argument, key, '=');
        std::getline(argument, value);
      } else {
        std::getline(argument, key);
        value = "true";
      }
      options[key] = value;
    }
  }

  Log::log_verbose = options["verbose"] == "true";

  // parse size to width and height
  std::istringstream size{options["size"]};
  std::string width_s, height_s;
  std::getline(size, width_s, 'x');
  std::getline(size, height_s);
  if (width_s.empty())
    width_s = "0";
  if (height_s.empty())
    height_s = "0";
  this->width = std::stoul(width_s);
  this->logger.log(Level::VERBOSE, "Setting width to " + std::to_string(this->width));
  this->height = std::stoul(height_s);
  this->logger.log(Level::VERBOSE, "Setting height to " + std::to_string(this->height));

  // parse input and output file path
  this->input_file = options["input_file"];
  this->logger.log(Level::VERBOSE, "Setting input file to " + this->input_file);
  this->output_file = options["output_file"];
  this->logger.log(Level::VERBOSE, "Setting output file to " + this->output_file);
}