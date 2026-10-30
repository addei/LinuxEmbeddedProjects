# LinuxEmbeddedProjects

Repository for small embedded Linux projects I built during my student days.
All projects are provided under the [GNU General Public License v2.0](./LICENSE).

## Contents

| Project | Description | Platform / Tools |
|---------|-------------|------------------|
| [`ipv4_16x2/`](./ipv4_16x2) | C program that displays the Raspberry Pi's IPv4 address on a Hitachi hd44780 16x2 LCD screen (4-bit mode). Installs via script and runs periodically through cron. | Raspberry Pi 2–4, WiringPi, gcc, make, cron |
| [`random_num_gen/`](./random_num_gen) | Interactive command-line program that generates unique random numbers in a user-given range, with optional single value or full list output. | Linux, gcc, make, Linux uinput |
| [`virtRasp/`](./virtRasp) | Step-by-step guide for emulating Raspberry Pi OS (aarch64) on openSUSE Tumbleweed (x86-64) using QEMU, including image setup, partition offset calculation, fstab configuration, and networking. | openSUSE Tumbleweed, QEMU, zypper/YaST |

## Quick start

Each subdirectory is a self-contained project with its own README and build instructions:

```bash
# 1. Enter a project folder
cd ipv4_16x2

# 2. Read its README for requirements and steps
cat README.md

# 3. Build (where applicable)
make
```

### ipv4_16x2 — IPv4 address on LCD
- **Build:** `make`
- **Install:** `chmod +x install.sh && ./install.sh` (installs to `/opt/bin/ipv4_16x2` and adds a cronjob)
- **Note:** If your network interface is not `eth0`, edit line 26 of `source/main.c` and rebuild.

### random_num_gen — Random number generator
- **Build:** `make`
- Run the resulting binary and follow the prompts to set iterations and range.

### virtRasp — QEMU Raspberry Pi emulation guide
- Follow [`virtRasp/README.md`](./virtRasp/README.md) to install QEMU on openSUSE Tumbleweed, download a Raspberry Pi OS 64-bit image, compute partition offsets, and boot the emulated system.

## License

All code in this repository is licensed under the [GNU General Public License v2.0](./LICENSE) unless noted otherwise in a subdirectory.
