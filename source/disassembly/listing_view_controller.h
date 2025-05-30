#include "base.h"
#include "binaryfile.h"
#include <QtWidgets/QTextEdit>
#include "../mainwindow.h"
#include "instructions.h"


class ListingViewController {
public:
    ListingViewController(BinaryFile &file, MainWindow *mainWindow);
    void setScriptById(stringid_64 id);
    void createListingView();

private:
    BinaryFile m_currentFile;
    MainWindow *m_mainWindow;

    void insertSpan(const std::string &text, QColor color = MainWindow::BLANK_COLOR, int fonzSize = 10, u8 indent = 0);
    void insertComment(const std::string &comment, u8 indent = 0);
    void insertHash(const std::string &hash, b8 surround = false);
    void insertHeaderLine();
    FunctionDisassembly createFunctionDisassembly(ScriptLambda *lambda);
    void processInstruction(StackFrame &stackFrame, FunctionDisassemblyLine &functionLine);
    void insertFunctionDisassemblyText(const FunctionDisassembly &functionDisassembly);
    void checkSymbolTableLoad(const Instruction &instruction, u64 * const tablePtr, std::map<u8, SymbolTableEntry> &symbols);
    u32 getOffset(const void *symbol);
};