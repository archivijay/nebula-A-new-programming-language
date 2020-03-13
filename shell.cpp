#include<iostream>
#include<exception>
#include<fstream>
#include<string>
#include<vector>
#include<queue>

#include "tokenizing_helper.hpp"
#include "program_elements/program_elements.hpp"
#include "tokenizer/tokenizer.hpp"
#include "parser/parser.hpp"
#include "exceptions/nebula_exceptions.hpp"



int main(int argc, char* argv[]){
	
	std::set_terminate(terminate_handler);
	
	
	if (argc < 1) throw std::exception(); // change this
	std::string file_name = argv[1];
	
	
	std::ifstream input_file(file_name);
	
	std::queue<std::vector<Token> > program_tokens = tokenizing_helper(input_file);
	
	Block* program_block = program_parser(program_tokens);
	
//	parser tests - 2 
//	if(!program_block->get_elements()->at(0)) std::cout << "Empty block\n";
	program_block->_repr_();
	
//	parser_tests
//	for(Element* e : program_block.get_elements()){
//		if (!e) std::cout << "NULL\n";
//	}
	
//	tokenizer tests
//	while(!program_tokens.empty()){
//		std::vector<Token> t = program_tokens.front();
//		program_tokens.pop();
//		
//		for(Token x: t){
//			std::cout << "'" << x.get_token_data() << "'" << std::endl;
//		}
//		std::cout << std::endl;
//	}


		
	return 0;
}
