*This project has been created as part of the 42 curriculum by agedikog.*

# NetPractice

## Description

NetPractice is a project focused on understanding the basics of computer networks.

The goal is to learn how devices communicate by correctly configuring IP addresses,
subnet masks, and default gateways.

The project consists of 10 levels. In each level, a network is given with some
incorrect configurations. The task is to fix these configurations so that all
devices can communicate with each other.

---

## Instructions

### Running the training interface

1. Download and extract the NetPractice project.
2. Go into the project folder.
3. Run:

```bash
./run.sh
```

If it does not work, you can start the server manually:

```bash
python3 -m http.server 49242
```

Then open this in your browser:

```
http://localhost:49242
```

---

### Solving levels

Each level shows a network with hosts and routers.

You need to fill in:
- IP addresses
- Subnet masks
- Default gateways

Use:
- **Check again** to test your solution
- **Get my config** to export your configuration
- **Next level** to continue

---

### Submission

You must submit 10 configuration files (one per level).

All files should be placed at the root of the repository:

```
NetPractice/
 ├─ level1
 ├─ level2
 ├─ level3
 ├─ level4
 ├─ level5
 ├─ level6
 ├─ level7
 ├─ level8
 ├─ level9
 ├─ level10
 └─ README.md
```

---

## Resources

Some useful resources:

- https://www.cloudflare.com/learning/network-layer/what-is-an-ip-address/
- https://www.ibm.com/docs/en/aix/7.2?topic=protocols-tcpip-addressing
- https://www.geeksforgeeks.org/computer-network-tcp-ip-model/

### Networking concepts

- TCP/IP addressing
- Subnet masks
- Default gateway
- Routing
- Routers and switches
- Basic OSI layers

### AI Usage

I used AI while learning and researching networking concepts during this project.
All configurations were done and checked by myself.