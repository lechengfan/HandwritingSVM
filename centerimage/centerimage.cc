/****
 * Calculates the center of gravity of an image. 
 * Approach (simple for the first iteration):
 * - create a matrix where pixel values <= 127 are marked 0 and values >= 128 are marked 1
 * - calculate the average location of all 1 valued pixels
 * - shift the average location to move it to the center
 ****/
