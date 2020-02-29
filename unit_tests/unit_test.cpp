// #include "RSeparatorTest.cpp"
#include "../src/RAnd.cpp"
#include "../src/ROr.cpp"
#include "../src/RSeparator.cpp"
#include "../src/RShellExec.cpp"
#include "../src/RParser.cpp"
// #include "RParserTest.cpp"
// #include "ROrTest.cpp"
// #include "RAndTest.cpp"
// #include "RParserTest.cpp"
// #include "RSeparatorTest.cpp"
#include "RExecTest.cpp"
// #include "src/RSeparator.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}