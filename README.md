XACC Examples
=============

Some examples of using [XACC][1] I am pushing up in case termites eat my hard
drive. [The AIDE-QC website][7] may have some useful information for installing XACC.

`make` will build all the examples, and you can run them with `./bell` or
`./xx_xacc`.

`bell` runs a trivial bell state circuit on the [Quantum++][2] backend, and
`xx_xacc` does basically the same thing, but with a [Mølmer-Sørensen][3] gate I
added to the IR for ion trap business.

The available IR instructions aren't documented as far as I can tell, but you
can look at [`CommonGates.hpp`][4] in the XACC source code. XACC backends are
implemented in [XACC plugins][5]. Here's [the Quantum++ backend][6], for
example.

[1]: https://github.com/eclipse/xacc/
[2]: https://github.com/softwareQinc/qpp
[3]: https://en.wikipedia.org/wiki/M%C3%B8lmer%E2%80%93S%C3%B8rensen_gate
[4]: https://github.com/eclipse/xacc/blob/master/quantum/gate/ir/CommonGates.hpp
[5]: https://github.com/eclipse/xacc/tree/master/quantum/plugins
[6]: https://github.com/eclipse/xacc/blob/master/quantum/plugins/qpp/accelerator/QppAccelerator.hpp
[7]: https://aide-qc.github.io/deploy/
