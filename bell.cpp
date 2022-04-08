#include <xacc/xacc.hpp>

int main(int argc, char **argv) {
    xacc::Initialize(argc, argv);
    xacc::set_verbose(true);

    //auto qpu = xacc::getAccelerator("gtri", {std::make_pair<std::string, std::string>("watchdir", "/home/austin/Documents/school/gatech/grad/iontrap/gtri-iontrap/watchdir")});
    auto qpu = xacc::getAccelerator("qpp", {{"shots", 1024}});

    xacc::qasm(R"(
        .compiler xasm
        .circuit bell
        .qbit q

        H(q[0]);
        CNOT(q[0], q[2]);
        CNOT(q[2], q[1]);
        Measure(q[0]);
        Measure(q[1]);
        Measure(q[2]);
    )");

    auto bell = xacc::getCompiled("bell");
    auto buf = xacc::qalloc(3);

    qpu->execute(buf, bell);
    buf->print();

    xacc::Finalize();
    return 0;
}
