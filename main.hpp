json read_file(char *fp);
void write_file(char *fp, json j);

bool confirm_action(char *msg);

std::string prependHome(std::string path);

fs::path getPath(std::string path, bool isFile, bool create);
fs::path getPath(std::string path, bool isFile);

