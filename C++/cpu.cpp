#include <iostream>
using namespace std;

class CPU {
private:
    int frequency;
    float voltage;
public:
    CPU() : frequency(0), voltage(0.0f) {
        cout << "正在默认构造对象" << endl;
    }
    CPU(int f, float v) : frequency(f), voltage(v) {
        cout << "正在构造对象" << endl;
    }
    CPU(const CPU& other) : frequency(other.frequency), voltage(other.voltage) {
        cout << "正在复制构造对象" << endl;
    }
    int GetFrequency() const {
        return frequency;
    }
    float GetVoltage() const {
        return voltage;
    }
    void SetFrequency(int f) {
        frequency = f;
    }
    void SetVoltage(float v) {
        voltage = v;
    }
    void Print() const {
        cout << "CPU频率：" << frequency << endl;
        cout << "CPU电压：" << voltage << endl;
    }
    void Run() const {
        cout << "CPU开始运行!" << endl;
    }
    void Stop() const {
        cout << "CPU停止运行!" << endl;
    }
};

class COMPUTER {
private:
    CPU cpu;
    int price;
public:
    COMPUTER() : cpu(), price(0) {
        cout << "默认构造了一个COMPUTER!" << endl;
    }
    COMPUTER(const CPU& c, int p) : cpu(c), price(p) {
        cout << "初始化构造了一个COMPUTER!" << endl;
    }
    COMPUTER(const COMPUTER& other) : cpu(other.cpu), price(other.price) {
        cout << "调用COMPUTER的复制构造函数" << endl;
    }
    ~COMPUTER() {
        cout << "正在删除COMPUTER对象!" << endl;
    }
    void SetComputer(int frequency, float voltage, int p) {
        cpu.SetFrequency(frequency);
        cpu.SetVoltage(voltage);
        price = p;
    }
    void Print() const {
        cpu.Print();
        cout << "电脑价格：" << price << endl;
    }
    void Run() const {
        cpu.Run();
        cout << "COMPUTER开始运行!" << endl;
    }
    void Stop() const {
        cpu.Stop();
        cout << "COMPUTER停止运行!" << endl;
    }
};

int main() {
    CPU mycpu(2400, 2.8f);
    COMPUTER computer1(mycpu, 5000);
    computer1.Print();
    computer1.Run();
    computer1.Stop();
    COMPUTER computer2 = computer1;
    computer2.Print();
    computer2.SetComputer(3600, 3.2f, 6500);
    computer2.Print();
    return 0;
}