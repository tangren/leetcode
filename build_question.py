#!/usr/bin/python

import os
import sys
import urllib2

def get_problem_name(problem_url):
    if problem_url.endswith('/'):
        problem_url = problem_url[:-1]
        
    return problem_url.split('/')[-1]

def get_problem_desc(problem_url):
    return ""
    # TODO
    # request = urllib2.Request(problem_url)
    # response = urllib2.urlopen(request)
    # print response.read(b)

def gen_cpp_content(problem_name, problem_url, problem_desc):
    content = ""
    content += "/*\n"
    content += "     Problem: %s\n" % problem_name
    content += "         Url: %s\n" % problem_url
    content += " Description: %s\n" % problem_desc
    content += "*/\n\n"

    content += "#include <iostream>\n"
    content += "#include <gtest/gtest.h>\n"
    content += "\n"
    content += "using namespace std;\n"
    content += "using namespace testing;\n"
    content += "\n"

    content += "class Solution {\n"
    content += "public:\n"
    content += "};\n"
    content += "\n"

    content += "TEST(SolutionTest, testSimple) {\n"
    content += "}\n"
    content += "\n"
    
    return content

def gen_cpp_file(problem_dir, problem_name, problem_url, problem_desc):
    content = gen_cpp_content(problem_name, problem_url, problem_desc)
    f = open(os.path.join(problem_dir, problem_name + ".cpp"), 'w')
    f.write(content)
    f.close()

def gen_build_script(problem_dir, problem_name):
    gtest_dir = os.path.join("../gtest")
    gtest_inc = os.path.join(gtest_dir, "include")
    gtest_objs = [os.path.join(gtest_dir, "lib/gtest-all.o"),
                  os.path.join(gtest_dir, "lib/gtest_main.o")]
    content = "#!/bin/sh\n"
    content += ("g++ %s.cpp -o %s -I%s" +
                " %s  -lpthread -ldl" +
                "&&./%s") % (
        problem_name, problem_name,
        gtest_inc, ' '.join(gtest_objs),
        problem_name)
    script_file = os.path.join(problem_dir, "build.sh")
    f = open(script_file, 'w')
    f.write(content)
    f.close()
    os.system("chmod +x %s" % script_file)
    
if __name__ == '__main__':
    argc = len(sys.argv)
    if argc == 1:
        print "error arg count!"
        exit(-1)

    problem_url = sys.argv[1]
    problem_name = get_problem_name(problem_url)
    problem_desc = get_problem_desc(problem_url)

    cur_dir = os.path.split(os.path.realpath(__file__))[0]
    problem_dir = os.path.join(cur_dir, problem_name)
    os.system("mkdir -p " + problem_dir)
    
    gen_cpp_file(problem_dir, problem_name, problem_url, problem_desc)

    gen_build_script(problem_dir, problem_name)
    
    pass
