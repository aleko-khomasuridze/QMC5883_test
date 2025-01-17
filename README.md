# QMC5883_test

### **Static IP**
No CLI commands; configure static IPs directly in PC settings.

---

### **DHCP**
```bash
Router(config)# ip dhcp excluded-address 192.168.1.1 192.168.1.10
Router(config)# ip dhcp pool DHCP_POOL
Router(dhcp-config)# network 192.168.1.0 255.255.255.0
Router(dhcp-config)# default-router 192.168.1.1
Router(dhcp-config)# dns-server 8.8.8.8
Router(dhcp-config)# exit
Router(config)# interface FastEthernet0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# no shutdown
```

---

### **RIP**
```bash
Router(config)# router rip
Router(config-router)# version 2
Router(config-router)# no auto-summary
Router(config-router)# network 192.168.1.0
Router(config-router)# network 10.10.17.0
Router(config-router)# exit
```

---

### **OSPF**
```bash
Router(config)# router ospf 1
Router(config-router)# network 192.168.2.0 0.0.0.255 area 0
Router(config-router)# network 10.10.17.0 0.0.0.7 area 0
Router(config-router)# exit
```

---

### **InterVLAN**
**Create VLANs:**
```bash
Switch(config)# vlan 30
Switch(config-vlan)# name VLAN_30
Switch(config-vlan)# exit
Switch(config)# vlan 40
Switch(config-vlan)# name VLAN_40
Switch(config-vlan)# exit
Switch(config)# vlan 50
Switch(config-vlan)# name VLAN_50
Switch(config-vlan)# exit
```

**Assign VLANs:**
- VLAN 30:
  ```bash
  Switch(config)# interface range FastEthernet0/1 - 4
  Switch(config-if-range)# switchport mode access
  Switch(config-if-range)# switchport access vlan 30
  ```
- VLAN 40:
  ```bash
  Switch(config)# interface range FastEthernet0/5 - 6
  Switch(config-if-range)# switchport mode access
  Switch(config-if-range)# switchport access vlan 40
  ```
- VLAN 50:
  ```bash
  Switch(config)# interface range FastEthernet0/7 - 8
  Switch(config-if-range)# switchport mode access
  Switch(config-if-range)# switchport access vlan 50
  ```

**Router-on-a-Stick:**
```bash
Router(config)# interface GigabitEthernet0/0.30
Router(config-subif)# encapsulation dot1Q 30
Router(config-subif)# ip address 192.168.30.1 255.255.255.0
Router(config-subif)# exit

Router(config)# interface GigabitEthernet0/0.40
Router(config-subif)# encapsulation dot1Q 40
Router(config-subif)# ip address 192.168.40.1 255.255.255.0
Router(config-subif)# exit

Router(config)# interface GigabitEthernet0/0.50
Router(config-subif)# encapsulation dot1Q 50
Router(config-subif)# ip address 192.168.50.1 255.255.255.0
Router(config-subif)# exit
```

**Enable Trunking:**
```bash
Switch(config)# interface FastEthernet0/24
Switch(config-if)# switchport mode trunk
```