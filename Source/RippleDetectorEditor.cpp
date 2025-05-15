// v060422
#include "RippleDetectorEditor.h"

// Class constructor
RippleDetectorEditor::RippleDetectorEditor (GenericProcessor* parentNode)
    : GenericEditor (parentNode)
{
    rippleDetector = (RippleDetector*) parentNode;

    desiredWidth = 450; //Plugin's desired width`

    int align1 = 10;

    /* Ripple Detection Settings */
    addSelectedChannelsParameterEditor (Parameter::ParameterScope::STREAM_SCOPE, "Ripple_Input", align1, 25);
    ParameterEditor* rippleInput = getParameterEditor ("Ripple_Input");
    rippleInput->setLayout (ParameterEditor::Layout::nameOnTop);
    rippleInput->setSize (80, 34);

    addTtlLineParameterEditor (Parameter::ParameterScope::STREAM_SCOPE, "Ripple_Out", align1, 60);
    ParameterEditor* rippleOut = getParameterEditor ("Ripple_Out");
    rippleOut->setLayout (ParameterEditor::Layout::nameOnTop);
    rippleOut->setSize (80, 34);

    /* Calibration Button */
    calibrateButton = std::make_unique<UtilityButton> ("CALIBRATE");
    calibrateButton->addListener (this);
    calibrateButton->setRadius (3.0f);
    calibrateButton->setBounds (align1, 102, 80, 20);
    addAndMakeVisible (calibrateButton.get());

    int align2 = 98;

    addTextBoxParameterEditor (Parameter::STREAM_SCOPE, "ripple_std", align2, 31);
    ParameterEditor* rippleStd = getParameterEditor ("ripple_std");
    rippleStd->setSize (150, 17);

    addTextBoxParameterEditor (Parameter::STREAM_SCOPE, "time_thresh", align2, 56);
    ParameterEditor* timeThresh = getParameterEditor ("time_thresh");
    timeThresh->setSize (150, 17);

    addTextBoxParameterEditor (Parameter::STREAM_SCOPE, "refr_time", align2, 81);
    ParameterEditor* refrTime = getParameterEditor ("refr_time");
    refrTime->setSize (150, 17);

    addTextBoxParameterEditor (Parameter::STREAM_SCOPE, "rms_samples", align2, 106);
    ParameterEditor* rmsSamples = getParameterEditor ("rms_samples");
    rmsSamples->setSize (150, 17);

    /* EMG / ACC Movement Detection Settings */
    int align3 = 255;
    addComboBoxParameterEditor (Parameter::ParameterScope::STREAM_SCOPE, "mov_detect", align3, 22);
    ParameterEditor* movDetect = getParameterEditor ("mov_detect");
    movDetect->setLayout (ParameterEditor::Layout::nameOnTop);
    movDetect->setSize (90, 34);

    addSelectedChannelsParameterEditor (Parameter::ParameterScope::STREAM_SCOPE, "Mov_Input", align3, 57);
    ParameterEditor* movInput = getParameterEditor ("Mov_Input");
    movInput->setLayout (ParameterEditor::Layout::nameOnTop);
    movInput->setSize (90, 34);

    addTtlLineParameterEditor (Parameter::ParameterScope::STREAM_SCOPE, "Mov_Out", align3, 92);
    ParameterEditor* movOut = getParameterEditor ("Mov_Out");
    movOut->setLayout (ParameterEditor::Layout::nameOnTop);
    movOut->setSize (90, 34);

    int align4 = 350;
    addTextBoxParameterEditor (Parameter::STREAM_SCOPE, "mov_std", align4, 22);
    ParameterEditor* movStd = getParameterEditor ("mov_std");
    movStd->setLayout (ParameterEditor::Layout::nameOnTop);
    movStd->setSize (90, 34);

    addTextBoxParameterEditor (Parameter::STREAM_SCOPE, "min_time_st", align4, 57);
    ParameterEditor* minTimeSt = getParameterEditor ("min_time_st");
    minTimeSt->setLayout (ParameterEditor::Layout::nameOnTop);
    minTimeSt->setSize (90, 34);

    addTextBoxParameterEditor (Parameter::STREAM_SCOPE, "min_time_mov", align4, 92);
    ParameterEditor* minTimeMov = getParameterEditor ("min_time_mov");
    minTimeMov->setLayout (ParameterEditor::Layout::nameOnTop);
    minTimeMov->setSize (90, 34);
}

void RippleDetectorEditor::buttonClicked (Button*)
{
    /* Calibration button was clicked */
    rippleDetector->shouldCalibrate = true;
}

// Called when settings are updated
void RippleDetectorEditor::updateSettings() {}
