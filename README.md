# Festival Management System (CPP)

A comprehensive C++ application designed to manage festival operations including scenes, artists, and technicians. The system provides an interactive console interface for festival administrators to efficiently organize and manage festival events.

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Class Structure](#class-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Menu Options](#menu-options)
- [Contributing](#contributing)
- [License](#license)

## Project Overview

The Festival Management System is a C++ console application that simulates the management of a music festival. It allows administrators to:
- Manage multiple scenes at a festival
- Register and track artists performing at the festival
- Assign technicians to manage scenes
- Track important dates and calculate durations

The system uses object-oriented programming principles with clear separation of concerns between different entities in the festival management domain.

## Features

### Scene Management
- Create new scenes with unique codes and names
- Modify existing scene details
- Delete scenes when no longer needed
- Set capacity limits for artists per scene
- Assign technician responsible for each scene

### Artist Management
- Register artists with personal and professional details
- Assign artists to specific scenes
- Remove artists from scenes
- Track artist registration dates
- View recently registered artists

### Technician Management
- Register technicians with specialization details
- Assign technicians to scenes
- Track employment dates and salaries
- Filter scenes by assigned technician

### Statistics and Reporting
- Display all scenes in the festival
- Identify scenes that have been active for more than 5 years
- Show scenes managed by specific technicians
- Calculate seniority of scenes based on service dates

## System Architecture

The system is built using a modular architecture with the following core classes:

### Core Classes
- **FestivalManager**: Main controller class that manages all scenes in the festival
- **Scene**: Represents a physical stage/area at the festival
- **Artiste**: Represents a musical artist performing at the festival
- **Technicien**: Represents a technician responsible for scene operations
- **Date**: Utility class for handling date operations and calculations

### Relationships
- FestivalManager contains multiple Scenes
- Scene contains multiple Artistes and one Technicien
- All entities have Date attributes for tracking important timeline information

## Class Structure

### Artiste Class
Manages artist information and details:
- `identifiant`: Unique identifier for the artist
- `nomScene`: Stage name of the artist
- `genreMusical`: Musical genre of the artist
- `paysOrigine`: Country of origin
- `cachet`: Performance fee
- `dateInscription`: Registration date

### Scene Class
Manages scene/stage information:
- `code`: Unique identifier for the scene
- `nom`: Name of the scene
- `technicienResponsable`: Technician responsible for the scene
- `nbMaxArtistes`: Maximum number of artists allowed on the scene
- `artistes`: Vector containing all artists assigned to the scene
- `dateMiseEnService`: Date when the scene was put into service

### Technicien Class
Manages technician information:
- `identifiant`: Unique identifier for the technician
- `nom`, `prenom`: Name details
- `specialite`: Technical specialty
- `salaire`: Salary information
- `dateEmbauche`: Employment date

### Date Class
Utility class for date handling:
- `jour`, `mois`, `annee`: Day, month, year components
- Methods for input/output and date calculations
- Difference calculation between dates

### FestivalManager Class
Main management class:
- Contains vector of all scenes
- Provides methods for scene operations
- Implements business logic for festival management

## Installation

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC) supporting C++11 or later
- Standard Template Library (STL)

### Building the Project

1. Clone or download the project files
2. Navigate to the project directory
3. Compile the source files:

```bash
g++ -std=c++11 *.cpp -o festival_manager
```

Or with a more explicit command:

```bash
g++ -std=c++11 main.cpp Artiste.cpp Date.cpp FestivalManager.cpp Scene.cpp Technicien.cpp -o festival_manager
```

### Running the Application

After successful compilation:

```bash
./festival_manager
```

## Usage

The application provides an interactive menu-driven interface. Upon launching, you'll see the main menu:

```
=== BOUM BOUM FESTIVAL ===
1. Gestion des Scènes
2. Gestion des Artistes (via Scène)
3. Affichage & Statistiques
0. Quitter
```

Navigate through the menus using numeric input and follow the prompts for each operation.

### Menu Options

#### 1. Scene Management
- **Add Scene**: Create a new scene by providing:
  - Scene code (unique identifier)
  - Scene name
  - Maximum number of artists
  - Technician details (ID, name, specialty, salary, hire date)
  - Service start date
- **Modify Scene**: Update an existing scene's information
- **Delete Scene**: Remove a scene from the system

#### 2. Artist Management
- **Add Artist to Scene**: Register a new artist to a specific scene by providing:
  - Artist ID
  - Stage name
  - Musical genre
  - Country of origin
  - Performance fee
  - Registration date
- **Remove Artist from Scene**: Delete an artist from a specific scene

#### 3. Display & Statistics
- **Display All Scenes**: Show information for all registered scenes
- **Scenes > 5 Years**: List scenes that have been in service for more than 5 years
- **Scenes by Technician**: Show all scenes managed by a specific technician ID
- **Recent Artists**: Display recently registered artists for a specific scene

## Technical Details

### Data Persistence
The current implementation stores all data in memory during runtime. Data is lost when the application terminates.

### Error Handling
- Input validation for numeric values
- Scene existence checks before operations
- Proper error messages for invalid operations

### Memory Management
- Uses STL containers (vectors) for dynamic data storage
- Automatic memory management through RAII principles
- No manual memory allocation/deallocation required

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Make your changes
4. Commit your changes (`git commit -m 'Add amazing feature'`)
5. Push to the branch (`git push origin feature/amazing-feature`)
6. Open a Pull Request

## License

This project is open source and available under the MIT License.

## Acknowledgments

- Designed for educational purposes to demonstrate C++ OOP concepts
- Follows good C++ practices including encapsulation, constructors, and destructors
- Implements proper separation of interface and implementation using header files