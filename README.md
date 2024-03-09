<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/PabloPicose/OpenCVNodeEditor">
    <img src="resources/images/opencvnodeeditor_logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">OpenCV Node Editor</h3>

  <p align="center">
    project_description
    <br />
    <a href="https://github.com/github_username/repo_name"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/github_username/repo_name">View Demo</a>
    ·
    <a href="https://github.com/github_username/repo_name/issues">Report Bug</a>
    ·
    <a href="https://github.com/github_username/repo_name/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
# About the Project

[![Product Name Screen Shot][product-screenshot]](https://github.com/PabloPicose/OpenCVNodeEditor/blob/main/resources/images/preview.png)

The OpenCVNodeEditor project is an innovative open-source tool designed to simplify the process of image analysis and manipulation using OpenCV through a user-friendly graphical node editor interface. This project leverages the power of Qt 6 for its GUI components, CMake for building and compiling, and integrates OpenCV for comprehensive image processing functionalities.

## Key Features

- **Graphical Node-Based Editor**: At the heart of OpenCVNodeEditor is a visually intuitive node editor that allows users to create, connect, and configure a series of processing steps in an easy-to-understand graphical format. This approach demystifies complex image processing workflows, making them accessible to both novices and experienced professionals alike.

- **Extensive OpenCV Integration**: The project fully harnesses the capabilities of OpenCV, one of the most robust and versatile libraries for computer vision and image processing. Users can apply various operations such as face detection, image filtering, color conversion, and much more, directly within the node editor interface.

- **Custom Node Development**: Users are not limited to predefined nodes. The OpenCVNodeEditor platform supports the creation of custom nodes, enabling the addition of unique image processing functionalities tailored to specific project needs.

- **Cross-Platform Compatibility**: Thanks to Qt 6, the project is designed to be cross-platform, supporting various operating systems including Windows, macOS, and Linux. This ensures that a wide range of users can access and benefit from the tool, regardless of their preferred development environment.

## Motivation

The motivation behind OpenCVNodeEditor was to address the steep learning curve associated with image processing and computer vision applications. By providing a graphical interface for constructing and visualizing workflows, the project aims to lower the barrier to entry, fostering innovation and experimentation in fields ranging from academic research to industry-specific applications.


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

This section guides you through the initial setup and building of the OpenCVNodeEditor project. The project leverages Qt (version 6+), CMake for building, and requires OpenCV as a dependency. It also integrates the [NodeEditor](https://github.com/paceholder/nodeeditor) for graphical node-based editing.

### Prerequisites

Before you begin, ensure you have the following installed on your system:
- Git
- CMake
- Qt (version 6 or higher)

### Setup

1. **Clone the OpenCVNodeEditor Repository**

   First, clone the OpenCVNodeEditor repository to your local machine using Git:

   ```bash
   git clone https://github.com/yourgithubusername/OpenCVNodeEditor.git
   cd OpenCVNodeEditor
   mkdir 3rdparty
    ```
   Clone the NodeEditor repository from GitHub into the 3rdparty directory you just created
   ```bash
   git clone https://github.com/paceholder/nodeeditor.git 3rdparty/nodeeditor
    ```
2. **Install OpenCV**
    Ensure OpenCV is installed on your system. You can download and install it from the OpenCV official website or use your distribution's package manager

<!-- USAGE EXAMPLES -->
## Example detected faces

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

1. **Scale image**
    In this example we will use the "Scale" node to resize an image. The node has two input ports, one for the image and another for the scale factor. The output port will be the resized image. We will scale the image by a factor of 0.15
    ![](https://github.com/PabloPicose/OpenCVNodeEditor/blob/main/resources/gif/scale.gif)

2. **Convert color**
    In this example we will use the "Convert color" node to convert an image from BGR to Grayscale. The node has two input ports, one for the image and another for the conversion code. The output port will be the converted image. We will use the conversion code "Grayscale8"
    ![](https://github.com/PabloPicose/OpenCVNodeEditor/blob/main/resources/gif/convert_color.gif)

3. **Detect faces**
    In this example we will use the "Detect multiscale" node to detect faces in an image. First we will use the Equalize Hist node to convert the image to an image with better contrast. Then with the "File" node we will load the cascade file and create the CascadeClassifier. Finally we will use the "Detect multiscale" node to detect the faces in the image. The output is a list of rectangles that represent the faces. Then we can simply draw the rectangles in the resized image (the equalized image or the scaled).
    
     We will use the cascade file "haarcascade_frontalface_alt.xml" that can be found in the [OpenCV repository frontal face alt](https://github.com/opencv/opencv/blob/4.x/data/haarcascades/haarcascade_frontalface_alt.xml) link.
    ![](https://github.com/PabloPicose/OpenCVNodeEditor/blob/main/resources/gif/detect_multiscale.gif)

4. **Detect faces on original**
   We will scale the Rectangles x 15 and draw them on the original image
    ![](https://github.com/PabloPicose/OpenCVNodeEditor/blob/main/resources/gif/detect_multiscale_on_original.gif)


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Files from link 
- [ ] Input video
    - [ ] Camera input
    - [ ] Take screenshot from video to an image
- [ ] Draws 
    - [ ] Circles

See the [open issues](https://github.com/PabloPicose/OpenCVNodeEditor/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Your Name - [@twitter_handle](https://twitter.com/twitter_handle) - email@email_client.com

Project Link: [https://github.com/github_username/repo_name](https://github.com/github_username/repo_name)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments
 
* [NodeEditor Qt](https://github.com/paceholder/nodeeditor)
* [OpenCV](https://github.com/opencv/opencv)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/PabloPicose/OpenCVNodeEditor/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://www.linkedin.com/in/pablo-p-a89533146/
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[product-screenshot]: resources/images/preview.png

[gif-convert_color]: resources/images/convert_color.gif
[gif-detect_multiscale]: resources/images/detect_multiscale.gif
[gif-detect_multiscale_on_original]: resources/images/detect_multiscale_on_original.gif
[gif-scale]: resources/images/scale.gif