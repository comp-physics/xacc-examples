#include <xacc/xacc.hpp>

int main(int argc, char **argv) {
    xacc::Initialize(argc, argv);
    xacc::set_verbose(true);

    auto qpu = xacc::getAccelerator("qpp", {{"shots", 8192}});

    // Fun times with our friend the Molmer-Sorenson gate
    xacc::qasm(R"(
        .compiler xasm
        .circuit yeehaw
        .qbit q

        H(q[0]);

        Ry(q[0], -pi/2);
        XX(q[0], q[1], pi/4);
        Ry(q[0], pi/2);
        Rz(q[0], pi/2);
        Rx(q[1], pi/2);

        Measure(q[0]);
        Measure(q[1]);
    )");

    auto yeehaw = xacc::getCompiled("yeehaw");
    auto buf = xacc::qalloc(2);

    qpu->execute(buf, yeehaw);
    buf->print();

    xacc::Finalize();
    return 0;
}
