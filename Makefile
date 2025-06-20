adjourn: 
	g++ main.cpp -o adjourn
clean:
	rm --force adjourn
deps:
	mkdir --parents deps
	wget https://raw.githubusercontent.com/nlohmann/json/refs/heads/develop/single_include/nlohmann/json.hpp --directory-prefix deps
remake:
	make clean; make
