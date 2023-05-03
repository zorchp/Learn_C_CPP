#include <cstddef>
#include <iostream>
#include <string>
using namespace std;


class OrderApi {
public:
    virtual int getOrderProductNum() = 0;
    virtual void setOrderProductNum(int num) = 0;
    virtual string getOrderContent() = 0;

protected:
    OrderApi() {}
};


class HomeOrder : public OrderApi {
public:
    int getOrderProductNum() { return m_orderProductNum; }
    void setOrderProductNum(int num) { m_orderProductNum = num; }

    string getOrderContent() {
        return "Customer is " + m_strCustomerName + " id is " + m_strProductId +
               ", Num is " + to_string(m_orderProductNum);
    }

    void setCustomerName(string name) { m_strCustomerName = name; }
    string getCustomerName() { return m_strCustomerName; }

    void setProductId(string id) { m_strProductId = id; }
    string getProductId() { return m_strProductId; }

private:
    string m_strCustomerName;
    string m_strProductId;
    int m_orderProductNum;
};

class AbroadOrder : public OrderApi {
public:
    int getOrderProductNum() { return m_orderProductNum; }
    void setOrderProductNum(int num) { m_orderProductNum = num; }

    string getOrderContent() {
        return "Customer is " + m_strCustomerName + " id is " + m_strProductId +
               ", Num is " + to_string(m_orderProductNum);
    }

    void setCustomerName(string name) { m_strCustomerName = name; }
    string getCustomerName() { return m_strCustomerName; }

    void setProductId(string id) { m_strProductId = id; }
    string getProductId() { return m_strProductId; }

private:
    string m_strCustomerName;
    string m_strProductId;
    int m_orderProductNum;
};

class OrderBusiness {
public:
    // 拆分订单
    void saveOrder(OrderApi* pOrder) {
        while (pOrder->getOrderProductNum() > 200) {
            // 新建订单
            OrderApi* pNewOrder = nullptr;
            if (dynamic_cast<HomeOrder*>(pOrder) != nullptr) {
                // 创建新对象, 暂存目标
                HomeOrder* p2 = new HomeOrder;
                HomeOrder* p1 = static_cast<HomeOrder*>(pOrder);
                p2->setOrderProductNum(200);
                p2->setCustomerName(p2->getCustomerName());
                p2->setProductId(p1->getProductId());
                pNewOrder = p2;
            }
            if (dynamic_cast<AbroadOrder*>(pOrder) != nullptr) {
                // 创建新对象, 暂存目标
                AbroadOrder* p2 = new AbroadOrder;
                AbroadOrder* p1 = static_cast<AbroadOrder*>(pOrder);
                p2->setOrderProductNum(200);
                p2->setCustomerName(p2->getCustomerName());
                p2->setProductId(p1->getProductId());
                pNewOrder = p2;
            }

            pOrder->setOrderProductNum(pOrder->getOrderProductNum() - 200);
            cout << "new Order is " << pNewOrder->getOrderContent() << endl;
        }
        cout << "The last order is " << pOrder->getOrderContent() << endl;
    }
};


int main(int argc, char* argv[]) {
    // HomeOrder* pHome = new HomeOrder;
    AbroadOrder* pHome = new AbroadOrder;
    pHome->setOrderProductNum(512);
    pHome->setCustomerName("Tom");
    pHome->setProductId("ID");

    OrderBusiness* pObj = new OrderBusiness;
    pObj->saveOrder(pHome);
    return 0;
}
