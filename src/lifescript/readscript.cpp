#include <lifescript/readscript.h>
#include <lifescript/lifescript.h>
#include <lifescript/lifescriptvisitor.h>
#include <LifeScriptLexer.h>
#include <LifeScriptParser.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace ul::script;
using namespace std;

LifeScript ul::script::readScript(string& filename) {
    // Open script file
    ifstream script(filename);
    if (!script.is_open()) {
        stringstream s;
        s << "ERROR Cannot open file " << filename;
        throw s;
    };

    // Parse using ANTLR
    antlr4::ANTLRInputStream input(script);
    LifeScriptLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    LifeScriptParser parser(&tokens);

    // Convert to LifeScript
    LifeScript config;
    LifeScriptConverterVisitor visitor(config);
    parser.script()->accept(&visitor);

    // Return LifeConfig
    return config;
}