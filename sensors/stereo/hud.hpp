#ifndef SENSORS_STEREO_HUD_HPP
#define SENSORS_STEREO_HUD_HPP

#include "opencv2/opencv.hpp"
#include <cv.h>
#include <iostream>

using namespace cv;
using namespace std;

class Hud {
    
    private:
        float airspeed_, altitude_;
        int frame_number_;
        int scale_factor_;
        const Scalar hud_color_ = Scalar(0.45, 0.95, 0.48); // green
        const int box_line_width_ = 2;
        const int text_font_ = FONT_HERSHEY_DUPLEX;
        const double hud_font_scale_ = 0.9;
        float text_thickness_ = 1;
        
        void PutHudText(Mat hud_img, string str_in, Point text_orgin);
        
        void DrawAirspeed(Mat hud_img);
        void DrawAltitude(Mat hud_img);
        void DrawLadder(Mat hud_img, float value, bool for_airspeed, int major_increment, int minor_increment);
        void DrawFrameNumber(Mat hud_img);
        //void DrawArtificialHorizon(Mat hud_img);
    
        int GetLadderBoxTop(Mat hud_img) { return hud_img.rows * 0.394; }
        int GetLadderBoxWidth(Mat hud_img) { return hud_img.cols * 0.10; }
        int GetLadderBoxHeight(Mat hud_img) { return hud_img.rows * 0.072; }
        int GetLadderArrowWidth(Mat hud_img) { return hud_img.cols * 0.025; }
        int GetAirspeedLeft(Mat hud_img) { return hud_img.cols * .045; }
        int GetAltitudeLeft(Mat hud_img) { return hud_img.cols * .833; }
    
    public:
        Hud();
        
        void SetAirspeed(float airspeed_in_mps) { airspeed_
            = 2.23694*airspeed_in_mps; }
        void SetAltitude(float altitude_in_meters) { altitude_ = 3.28084*altitude_in_meters; }
        void SetFrameNumber(int frame_number_in) { frame_number_ = frame_number_in; }
        
        void DrawHud(InputArray _input_image, OutputArray _output_image);
    
    
    
};

#endif