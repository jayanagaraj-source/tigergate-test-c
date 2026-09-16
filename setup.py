# Deliberately vulnerable pins for SCA scanner testing.
from setuptools import setup

setup(
    name="tigergate-test-c",
    version="0.2.0",
    description="Security-test fixture: same packages declared in multiple files.",
    install_requires=[
        "Flask==0.12.2",
        "Jinja2==2.10",
        "requests==2.19.1",
        "PyYAML==3.13",
        "urllib3==1.24.1",
        "cryptography==2.3",
        "Django==2.0.0",
        "paramiko==2.4.1",
    ],
)
