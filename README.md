
## About The Project
The `fixed_width_unsigned_integer_manipulation_library`(FWUIM) is a static `C` library for manipulating fixed width unsigned integer types. It supports `get`, `set`, `clear` and `toggle` manipulations for `uint8_t`, `uint16_t`, `uint32_t`, and `uint64_t` types defined in [stdint.h](https://en.cppreference.com/w/cpp/header/cstdint).

## Getting Started
To get a local copy up and running follow these simple steps.

### Prerequisites
FWUIM depends on the following softwares. Please ensure these software are available on your system before installing. 
* [gcc](https://gcc.gnu.org/install/)
* [make](https://www.gnu.org/software/make/)
* [cmake](https://cmake.org/install/)

On Ubuntu these prerequisites can be installed by running the following command
```sh
sudo apt install -y gcc make cmake ;
```

### Installation
1. Clone the repo
   ```sh
   git clone https://github.com/DVNLO/fixed_width_unsigned_integer_manipulation_library.git ;
   ```
2. Navigate to the project's `root` director.
   ```sh
   cd ./fixed_width_unsigned_integer_manipulation_library ;
   ```
3. Make a `build` director.
    ```sh
   mkdir ./build ;
   ```
4. Navigate to `build` director.
    ```sh
    cd ./build ;
   ```
5. Configure `cmake`.
    ```sh
    cmake .. ;
   ```
6. Build the project with `make`.
    ```sh
    make ;
    ```
When `make` completes, a static library `libfwuim.a` will be available in the build directory.

## Usage
Configure your build system to import the needed includes from `./include` and link agains the build static library `libfwuim.a`.

## Roadmap
See the [open issues](https://github.com/DVNLO/fixed_width_unsigned_integer_manipulation_library/issues) for a list of proposed features (and known issues).

## Contributing
Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License
Distributed under the MIT License. See `LICENSE` for more information.

## Contact

Dan Vyenielo - [https://www.linkedin.com/in/dan-vyenielo/](https://www.linkedin.com/in/dan-vyenielo/)

Project Link: [https://github.com/DVNLO/fixed_width_unsigned_integer_manipulation_library](https://github.com/DVNLO/fixed_width_unsigned_integer_manipulation_library)

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/github_username
