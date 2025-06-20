json read_file(char *fp);
void write_file(char *fp, json j);

bool confirm_action(char *msg);

std::string prependHome(std::string path);

fs::path getDir(std::string path, bool create);
fs::path getDir(std::string path);

std::fstream getFile(std::string path, bool create);
std::fstream getFile(std::string path);


