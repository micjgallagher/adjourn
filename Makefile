adjourn: 
	g++ main.cpp -o adjourn
clean:
	rm adjourn
deps:
	mkdir --parents deps
	wget https://raw.githubusercontent.com/nlohmann/json/refs/heads/develop/single_include/nlohmann/json.hpp --directory-prefix deps
