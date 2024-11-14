# Assembly Line Simulation
This project simulates an assembly line with multiple stations, each holding a set of stock items and serving customer orders as they move along the line. 
The assembly line is managed by a LineManager class, which directs customer orders through each station to fulfill their item requirements. Orders can be 
completed or marked as incomplete depending on inventory availability.

## Project Overview
The assembly line simulation is divided into several modules, each addressing key components of the assembly line process. It incorporates various 
object-oriented programming concepts and data management techniques, such as dynamic memory allocation, string parsing, and advanced C++ algorithms. 
This project also applies the Rule of Five for effective resource management.

## Modules and Key Concepts
### Module 1 (MS1). Utilities and Station Classes
- Utilities: A helper module to parse input data and configure the assembly line.
- Station: Manages individual stations that handle specific items. Each station keeps track of item details, including name, description, serial number, 
and stock quantity.

### Module 2 (MS2): CustomerOrder Class
- CustomerOrder: Represents customer orders with a list of required items. Orders move from station to station, where each item is either filled or remains 
unfilled based on station inventory.
- Utilizes dynamic memory management and the Rule of Five to ensure efficient handling of resources for each order. Algorithms such as std::all_of and std::copy 
are used to manage order items and ensure data integrity.

### Module 3 (MS3). Workstation and LineManager Modules 
- Workstation: Connects stations in sequence as an assembly line. Each workstation processes orders, fills items as needed, and forwards orders to the next station.
- LineManager: Manages the assembly line, directing customer orders through connected workstations based on the requirements specified in AssemblyLine.txt. 
Orders are categorized as pending, completed, or incomplete.

## Key Functionalities
- Order Management: Orders are moved through the line, where each station attempts to fill items based on availability.
- Inventory Handling: Each station has a stock of items, which are checked against customer order requirements. Orders 
may be marked incomplete if items are unavailable.
- Dynamic Allocation and Memory Management: The project uses dynamic allocation to handle order items and carefully manages 
resources with the Rule of Five.
- Algorithms: Advanced C++ algorithms (std::for_each, std::all_of) are used to streamline operations within the assembly line, improving efficiency and readability.

## Challenges and Learnings
- Key learning points include effective memory management, modular programming, and the use of algorithms to simplify complex processes. 
- The structured milestone instructions were essential in guiding the logic and implementation of each component.
