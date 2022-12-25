#  videolines

This is an OpenFrameworks project to display particle lines from a webcam capture.  The camera operates at a reduced frame rate and resolution.  The pixels from the capture are selected with a low probability.  However when captured it will spawn a particle that will grow to a size relative to the brightness of the pixel.  After reaching the initialized brightness, the particle will start dying off.  

The sizes are currently hard coded along with the probability.  At the current settings it can obtain ~30fps.
