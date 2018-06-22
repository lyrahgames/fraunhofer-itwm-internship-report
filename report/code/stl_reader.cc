std::vector<Triangle> load(const std::string& file_path) {
  std::fstream file(file_path, std::ios::binary | std::ios::in);
  if (!file.is_open())
    throw std::runtime_error("File could not be opened! Does it exist?");

  file.ignore(80);

  std::uint32_t triangle_count;
  file.read(reinterpret_cast<char*>(&triangle_count), 4);

  std::vector<Triangle> triangles(triangle_count);

  for (auto i = 0; i < triangle_count; ++i) {
    file.read(reinterpret_cast<char*>(&triangles[i].normal), 12);
    file.read(reinterpret_cast<char*>(&triangles[i].vertex), 36);
    file.ignore(2);
  }

  return triangles;
}