#include "collage/collage.hpp"
#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <vector>

std::string file_to_string(const std::string &fileName){
  std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

  std::ifstream::pos_type fileSize = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  std::vector<char> bytes(fileSize);
  ifs.read(bytes.data(), fileSize);

  return std::string(bytes.data(), fileSize);
}

int main() {
  auto oldFile = file_to_string("old.txt");
  auto patchFile = file_to_string("patch.bin");

  auto patched = collage::patch(oldFile, patchFile);

  std::cout << patched;

  return 0;
}
