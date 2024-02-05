#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

// Example function for AI module
void processImage(const std::string& imagePath) {
    // Read the image
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cerr << "Could not read the image: " << imagePath << std::endl;
        return;
    }

    // Example processing: convert to grayscale
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Display the processed image
    cv::imshow("Processed Image", grayImage);
    cv::waitKey(0);
}

// Main function for AI module (for demonstration purposes)
int mainAI() {
    std::string imagePath = "path_to_image.jpg";
    processImage(imagePath);
    return 0;
}

