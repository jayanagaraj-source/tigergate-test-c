# Deliberately insecure test fixtures

This repository validates SCA, SAST, secret, IaC, container, and SBOM scanners.
It intentionally contains vulnerable code, outdated dependencies, fake
hard-coded credentials, and insecure infrastructure. **Do not deploy or reuse
these patterns.**

See `README.md` for build/run/scan instructions and `FINDINGS.md` for the full
expected-findings inventory (with CWE/CVE mapping).
