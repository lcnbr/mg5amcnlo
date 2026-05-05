# Spenso C++ Backend Replacement Plan

## Goal

Replace the current ALOHA C++ expression-emitting backend with the spenso-backed
backend while preserving the public HELAS C++ ABI: same routine names, same
argument order, same output arrays, and the same generated-process call sites.

The normal C++ writer can remain as a test oracle during the transition, but the
runtime replacement should not require a user-facing compatibility mode.

## Current State

- `ALOHAWriterForSpenso` emits a raw Symbolica/spenso evaluator plus a
  HELAS-shaped C++ wrapper.
- The wrapper builds `spenso_params` from the normal ALOHA C++ call argument
  order.
- Input momenta are packed adjacent to their wavefunction parameters where the
  spenso network needs them, for example `P2,V2,P3,V3`.
- The spenso parameter comments and expected cinds are derived through the
  tensor-network path rather than hard-coded.
- Source-level tests cover VVS, FFV, and VVV wrapper shape and parameter
  packing.
- Eval-level tests now compile normal C++ and spenso C++ for VVS/VVV routines,
  run both with identical inputs, and compare the full HELAS output arrays.

## Phase 1: Expand Eval Parity

- Add eval comparisons for the main HELAS output shapes:
  - scalar output,
  - spinor output,
  - vector output,
  - vertex output.
- Add representative Lorentz structures beyond the current VVS/VVV coverage:
  FFV with charge conjugation, FFS, SSS, SSV, VSS, and tensor/spin-2 routines
  if supported by the active spenso object coverage.
- Cover the denominator and coupling paths explicitly:
  non-zero masses, non-zero widths, massless outputs, and pure vertex routines.
- Keep using generated normal C++ as the numerical oracle until the spenso path
  is broad enough to become the default.
- Keep the eval harness compiler-agnostic by honoring `CXX` first, then falling
  back to `clang++`, `g++`, or `c++`.

## Phase 2: Finish ALOHA Object Coverage

- Use failed generation/eval cases as the inventory for missing `to_spenso`,
  `spenso_parameters`, and tensor-library registrations.
- Finish or verify support for all fixed tensors and special objects used by
  generated C++ routines:
  metric, identity, gamma matrices, charge conjugation, epsilon tensors,
  masses, widths, couplings, momenta, complex masses, spinors, vectors,
  scalars, and tensor wavefunctions.
- Keep expected parameter lists derived from `TensorNetwork(...).result_tensor()`
  so tests exercise the same expansion path as code generation.
- Avoid adding backend-specific ordering exceptions unless they follow from the
  existing normal C++ argument construction.

## Phase 3: Process-Export Integration

- Trace all places that request `language='CPP'` through `WriterFactory` and
  process export.
- Add test-only plumbing that can generate a small process once through normal
  C++ and once through spenso C++, then compile both outputs.
- Confirm generated headers, includes, auxiliary functions, and makefiles do not
  assume the old direct-expression backend.
- Make sure generated spenso files do not depend on temporary files or external
  runtime artifacts beyond the emitted C++ source.

## Phase 4: Regression Suite

- Add focused unit tests for object serialization and fixed tensor registration
  in `tests/unit_tests/core/test_spenso.py`.
- Add parallel ALOHA tests for wrapper signatures, parameter packing, cinds, and
  eval parity in `tests/parallel_tests/test_aloha.py`.
- Add at least one IO/process-level test that exercises the exported generated
  C++ in the same shape users compile.
- Keep generated fixture files small and intentional; ignore or untrack process
  dumps and backup artifacts.

## Phase 5: Flip the C++ Backend

- Once eval and process-export parity are in place, route the current C++ writer
  selection to the spenso-backed implementation.
- Preserve the `CPP` language key and generated HELAS ABI so downstream code does
  not need call-site changes.
- Keep the old normal C++ generation path only as an internal oracle while the
  replacement is being validated, then remove or quarantine it when it no longer
  carries test value.
- Run the focused spenso tests, the broader ALOHA parallel tests, and at least
  one generated-process compile before considering the backend replaced.

## Useful Test Commands

```bash
uv run python -m unittest tests.parallel_tests.test_aloha.TestAlohaWriter.test_short_spenso_cpp_eval_matches_cpp
```

```bash
uv run python tests/test_manager.py -pP -t0 test_short_spenso_cpp_eval_matches_cpp test_short_spenso_C test_short_spenso_FFV1_C test_short_cpp_and_spenso_C_generation test_short_spenso_params_follow_cpp_argument_order
```
