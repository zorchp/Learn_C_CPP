#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


// 或者用 to_string
template <typename T>
string ConvertToString(T value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

class ExportHeaderModel {
public:
    ExportHeaderModel(string did, string ed)
        : m_strDepId(did), m_strExportData(ed) {}
    string getDepId() { return m_strDepId; }
    string getExportData() { return m_strExportData; }

private:
    string m_strDepId;      // 对账单的部门
    string m_strExportData; // 对账单的导出 日期
};


class ExportDateModel {
public:
    ExportDateModel(string tid, double q) : m_strTransId(tid), m_Quantity(q) {}
    string getTransId() { return m_strTransId; }
    double getQuantity() { return m_Quantity; }

private:
    string m_strTransId;
    double m_Quantity;
};

class ExportFooterModel {
public:
    ExportFooterModel(string eu) : m_exportUser(eu) {}
    string getExportUser() { return m_exportUser; }

private:
    string m_exportUser;
};


class ExportToTxtHelper {
public:
    void doExport(ExportHeaderModel& ehm,
                  vector<ExportDateModel*>& edmCollection, // 可能有多笔交易记录
                  ExportFooterModel& efm) {
        // 字符串拼接
        string strTmp{};
        // 1. 写文件头
        strTmp += ehm.getDepId() + ", " + ehm.getExportData() + "\n";
        // 2. 写文件数据
        for (auto it = edmCollection.begin(); it != edmCollection.end(); ++it)
            strTmp += (*it)->getTransId() + ", " +
                      to_string((*it)->getQuantity()) + "\n";
        // 3. 拼接文件尾部
        strTmp += efm.getExportUser() + "\n";
        cout << strTmp;
    }
};

class ExportToXmlHelper {
public:
    void doExport(ExportHeaderModel& ehm,
                  vector<ExportDateModel*>& edmCollection, // 可能有多笔交易记录
                  ExportFooterModel& efm) {
        // 字符串拼接
        string strTmp{};
        // 1. 写文件头
        strTmp.append("<?xml version='1.0' encoding='utf-8'>\n");
        strTmp.append("<Receipt>\n");
        strTmp.append("    <Header>\n");
        strTmp.append("        <DepId>");
        strTmp.append(ehm.getDepId() + "</DepId>\n");
        strTmp.append("    <ExportDate>" + ehm.getExportData() +
                      "</ExportDate>\n");
        strTmp.append("    </Header>\n");

        // 2. 写文件数据
        strTmp.append("    <Body>\n");
        for (auto it = edmCollection.begin(); it != edmCollection.end(); ++it) {
            strTmp.append("        <id>" + (*it)->getTransId() + "</id>\n");
            strTmp.append("        <amount>" + to_string((*it)->getQuantity()) +
                          "</amount>\n");
        }
        strTmp.append("    </Body>\n");

        // 3. 拼接文件尾部
        strTmp.append("    <Footer>\n");
        strTmp.append("        <ExportUser>" + efm.getExportUser() +
                      "</ExportUser>\n");
        strTmp.append("    </Footer>\n</Receipt>\n");
        cout << strTmp;
    }
};


int main(int argc, char* argv[]) {
    ExportHeaderModel* pEhm =
        new ExportHeaderModel("南京 1 支行", "10 月 2 日");
    ExportDateModel* pEdm1 = new ExportDateModel("1", 1000.0f);
    ExportDateModel* pEdm2 = new ExportDateModel("2", 2000.0f);
    vector<ExportDateModel*> myVec{pEdm1, pEdm2};
    ExportFooterModel* pEfm = new ExportFooterModel("Tom");
    // ExportToTxtHelper helper;
    ExportToXmlHelper helper;
    helper.doExport(*pEhm, myVec, *pEfm);
    return 0;
}
