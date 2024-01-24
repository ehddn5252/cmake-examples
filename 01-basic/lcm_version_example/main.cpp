#include <iostream>
#include "lcm_version.h"
#include <regex>
int main(int argc, char *argv[])
{
   std::cout << "LCM Run" << std::endl;
   if (argc>1 && strcmp(argv[1],"--version")==0 ||strcmp(argv[1],"-v")==0){
      std::string current_branch_git_tag = CURRENT_BRANCH_GIT_TAG;
      std::string current_branch_git_tag_message = CURRENT_BRANCH_TAG_MESSAGE;
      std::string s = std::regex_replace(current_branch_git_tag_message,std::regex("@&~"),"\n");

      std::cout << "LCM Version" << std::endl;
      std::cout << current_branch_git_tag << std::endl;
      std::cout << s << std::endl;
   }
   return 0;
}