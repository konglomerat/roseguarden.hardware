/* Copyright by Binary Labs
 * Kunz & Schierling Ingenieursdienstleistungen GbR
 * binarylabs.dev
 *
 * Written for the roseguarden project and distributed
 * under the license stated in the LICENSE file
 */


#pragma once

#include "../types/Font.h"

namespace Graphics
{

const Font_t<66,1024,32> Font_Silkscreen_24 =
{
  { { 
     { /* */ 32, 15, { 0, 19 }, { 0, 19, 0, 0 }},
     { /*.*/ 46, 8, { 0, 15 }, { 0, 15, 4, 4 }},
     { /*0*/ 48, 23, { 4, 0 }, { 4, 0, 15, 19 }},
     { /*1*/ 49, 19, { 4, 0 }, { 19, 0, 11, 19 }},
     { /*2*/ 50, 23, { 4, 0 }, { 30, 0, 15, 19 }},
     { /*3*/ 51, 23, { 4, 0 }, { 45, 0, 15, 19 }},
     { /*4*/ 52, 23, { 4, 0 }, { 60, 0, 15, 19 }},
     { /*5*/ 53, 23, { 4, 0 }, { 75, 0, 15, 19 }},
     { /*6*/ 54, 24, { 4, 0 }, { 90, 0, 16, 19 }},
     { /*7*/ 55, 24, { 4, 0 }, { 106, 0, 16, 19 }},
     { /*8*/ 56, 23, { 4, 0 }, { 122, 0, 15, 19 }},
     { /*9*/ 57, 23, { 4, 0 }, { 137, 0, 15, 19 }},
     { /*:*/ 58, 8, { 0, 4 }, { 152, 4, 4, 11 }},
     { /*?*/ 63, 23, { 4, 0 }, { 156, 0, 15, 19 }},
     { /*A*/ 65, 23, { 4, 0 }, { 171, 0, 15, 19 }},
     { /*B*/ 66, 23, { 4, 0 }, { 186, 0, 15, 19 }},
     { /*C*/ 67, 23, { 4, 0 }, { 201, 0, 15, 19 }},
     { /*D*/ 68, 23, { 4, 0 }, { 216, 0, 15, 19 }},
     { /*E*/ 69, 19, { 4, 0 }, { 231, 0, 12, 19 }},
     { /*F*/ 70, 19, { 4, 0 }, { 243, 0, 12, 19 }},
     { /*G*/ 71, 23, { 4, 0 }, { 255, 0, 15, 19 }},
     { /*H*/ 72, 23, { 4, 0 }, { 270, 0, 15, 19 }},
     { /*I*/ 73, 12, { 4, 0 }, { 285, 0, 4, 19 }},
     { /*J*/ 74, 23, { 4, 0 }, { 289, 0, 15, 19 }},
     { /*K*/ 75, 23, { 4, 0 }, { 304, 0, 15, 19 }},
     { /*L*/ 76, 19, { 4, 0 }, { 319, 0, 12, 19 }},
     { /*M*/ 77, 27, { 4, 0 }, { 331, 0, 19, 19 }},
     { /*N*/ 78, 27, { 4, 0 }, { 350, 0, 19, 19 }},
     { /*O*/ 79, 23, { 4, 0 }, { 369, 0, 15, 19 }},
     { /*P*/ 80, 23, { 4, 0 }, { 384, 0, 15, 19 }},
     { /*Q*/ 81, 23, { 4, 0 }, { 399, 0, 15, 23 }},
     { /*R*/ 82, 23, { 4, 0 }, { 414, 0, 15, 19 }},
     { /*S*/ 83, 23, { 4, 0 }, { 429, 0, 15, 19 }},
     { /*T*/ 84, 19, { 4, 0 }, { 444, 0, 11, 19 }},
     { /*U*/ 85, 23, { 4, 0 }, { 455, 0, 15, 19 }},
     { /*V*/ 86, 27, { 4, 0 }, { 470, 0, 19, 19 }},
     { /*W*/ 87, 27, { 4, 0 }, { 489, 0, 19, 19 }},
     { /*X*/ 88, 27, { 4, 0 }, { 508, 0, 19, 19 }},
     { /*Y*/ 89, 27, { 4, 0 }, { 527, 0, 19, 19 }},
     { /*Z*/ 90, 20, { 4, 0 }, { 546, 0, 12, 19 }},
     { /*a*/ 97, 23, { 4, 0 }, { 558, 0, 15, 19 }},
     { /*b*/ 98, 23, { 4, 0 }, { 573, 0, 15, 19 }},
     { /*c*/ 99, 23, { 4, 0 }, { 588, 0, 15, 19 }},
     { /*d*/ 100, 23, { 4, 0 }, { 603, 0, 15, 19 }},
     { /*e*/ 101, 19, { 4, 0 }, { 618, 0, 12, 19 }},
     { /*f*/ 102, 19, { 4, 0 }, { 630, 0, 12, 19 }},
     { /*g*/ 103, 23, { 4, 0 }, { 642, 0, 15, 19 }},
     { /*h*/ 104, 23, { 4, 0 }, { 657, 0, 15, 19 }},
     { /*i*/ 105, 12, { 4, 0 }, { 672, 0, 4, 19 }},
     { /*j*/ 106, 23, { 4, 0 }, { 676, 0, 15, 19 }},
     { /*k*/ 107, 23, { 4, 0 }, { 691, 0, 15, 19 }},
     { /*l*/ 108, 19, { 4, 0 }, { 706, 0, 12, 19 }},
     { /*m*/ 109, 27, { 4, 0 }, { 718, 0, 19, 19 }},
     { /*n*/ 110, 27, { 4, 0 }, { 737, 0, 19, 19 }},
     { /*o*/ 111, 23, { 4, 0 }, { 756, 0, 15, 19 }},
     { /*p*/ 112, 23, { 4, 0 }, { 771, 0, 15, 19 }},
     { /*q*/ 113, 23, { 4, 0 }, { 786, 0, 15, 23 }},
     { /*r*/ 114, 23, { 4, 0 }, { 801, 0, 15, 19 }},
     { /*s*/ 115, 23, { 4, 0 }, { 816, 0, 15, 19 }},
     { /*t*/ 116, 19, { 4, 0 }, { 831, 0, 11, 19 }},
     { /*u*/ 117, 23, { 4, 0 }, { 842, 0, 15, 19 }},
     { /*v*/ 118, 27, { 4, 0 }, { 857, 0, 19, 19 }},
     { /*w*/ 119, 27, { 4, 0 }, { 876, 0, 19, 19 }},
     { /*x*/ 120, 27, { 4, 0 }, { 895, 0, 19, 19 }},
     { /*y*/ 121, 27, { 4, 0 }, { 914, 0, 19, 19 }},
     { /*z*/ 122, 20, { 4, 0 }, { 933, 0, 12, 19 }},
  }},
  {
    
  0x00, 0xFF, 0xF8, 0xC7, 0xFF, 0xE3, 0xFF, 0xF1, 0xF0, 0xF8, 0xFF, 0xC3,
  0x3F, 0xFC, 0xFF, 0xC3, 0x3F, 0xE0, 0x1F, 0xF0, 0xFF, 0x80, 0x3F, 0xFC,
  0x1F, 0xE0, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0x7F, 0xF8, 0xFF, 0x03, 0xFE,
  0x01, 0xE0, 0x0F, 0xF0, 0x07, 0x78, 0x00, 0xFC, 0x03, 0xE0, 0xE1, 0x1F,
  0xFF, 0x07, 0xF8, 0xC7, 0xFF, 0x03, 0xFE, 0xFF, 0xFF, 0x07, 0xF8, 0x03,
  0xE0, 0x1F, 0x00, 0xFF, 0x00, 0xF8, 0x07, 0xC0, 0xFF, 0x3F, 0xFC, 0xE1,
  0xFF, 0x00, 0xFF, 0xF8, 0x3F, 0xFC, 0xFF, 0xFF, 0xC3, 0xFF, 0x1F, 0xF0,
  0x0F, 0x00, 0x7F, 0x80, 0x3F, 0xC0, 0x03, 0xE0, 0x1F, 0x00, 0x0F, 0xFF,
  0xF8, 0x3F, 0xC0, 0x3F, 0xFE, 0x1F, 0xF0, 0xFF, 0xFF, 0x3F, 0xC0, 0x1F,
  0x00, 0xFF, 0x00, 0xF8, 0x07, 0xC0, 0x3F, 0x00, 0xFE, 0xFF, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xF8, 0xC7,
  0xFF, 0xE3, 0xFF, 0xF1, 0xF0, 0xF8, 0xFF, 0xC3, 0x3F, 0xFC, 0xFF, 0xC3,
  0x3F, 0xE0, 0x1F, 0xF0, 0xFF, 0x80, 0x3F, 0xFC, 0x1F, 0xE0, 0x1F, 0xFF,
  0x87, 0xFF, 0xFF, 0x7F, 0xF8, 0xFF, 0x03, 0xFE, 0x01, 0xE0, 0x0F, 0xF0,
  0x07, 0x78, 0x00, 0xFC, 0x03, 0xE0, 0xE1, 0x1F, 0xFF, 0x07, 0xF8, 0xC7,
  0xFF, 0x03, 0xFE, 0xFF, 0xFF, 0x07, 0xF8, 0x03, 0xE0, 0x1F, 0x00, 0xFF,
  0x00, 0xF8, 0x07, 0xC0, 0xFF, 0x3F, 0xFC, 0xE1, 0xFF, 0x00, 0xFF, 0xF8,
  0x3F, 0xFC, 0xFF, 0xFF, 0xC3, 0xFF, 0x1F, 0xF0, 0x0F, 0x00, 0x7F, 0x80,
  0x3F, 0xC0, 0x03, 0xE0, 0x1F, 0x00, 0x0F, 0xFF, 0xF8, 0x3F, 0xC0, 0x3F,
  0xFE, 0x1F, 0xF0, 0xFF, 0xFF, 0x3F, 0xC0, 0x1F, 0x00, 0xFF, 0x00, 0xF8,
  0x07, 0xC0, 0x3F, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xF8, 0xC7, 0xFF, 0xE3, 0xFF, 0xF1,
  0xF0, 0xF8, 0xFF, 0xC3, 0x3F, 0xFC, 0xFF, 0xC3, 0x3F, 0xE0, 0x1F, 0xF0,
  0xFF, 0x80, 0x3F, 0xFC, 0x1F, 0xE0, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0x7F,
  0xF8, 0xFF, 0x03, 0xFE, 0x01, 0xE0, 0x0F, 0xF0, 0x07, 0x78, 0x00, 0xFC,
  0x03, 0xE0, 0xE1, 0x1F, 0xFF, 0x07, 0xF8, 0xC7, 0xFF, 0x03, 0xFE, 0xFF,
  0xFF, 0x07, 0xF8, 0x03, 0xE0, 0x1F, 0x00, 0xFF, 0x00, 0xF8, 0x07, 0xC0,
  0xFF, 0x3F, 0xFC, 0xE1, 0xFF, 0x00, 0xFF, 0xF8, 0x3F, 0xFC, 0xFF, 0xFF,
  0xC3, 0xFF, 0x1F, 0xF0, 0x0F, 0x00, 0x7F, 0x80, 0x3F, 0xC0, 0x03, 0xE0,
  0x1F, 0x00, 0x0F, 0xFF, 0xF8, 0x3F, 0xC0, 0x3F, 0xFE, 0x1F, 0xF0, 0xFF,
  0xFF, 0x3F, 0xC0, 0x1F, 0x00, 0xFF, 0x00, 0xF8, 0x07, 0xC0, 0x3F, 0x00,
  0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFF, 0xF8, 0xC7, 0xFF, 0xE3, 0xFF, 0xF1, 0xF0, 0xF8, 0xFF, 0xC3,
  0x3F, 0xFC, 0xFF, 0xC3, 0x3F, 0xE0, 0x1F, 0xF0, 0xFF, 0x80, 0x3F, 0xFC,
  0x1F, 0xE0, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0x7F, 0xF8, 0xFF, 0x03, 0xFE,
  0x01, 0xE0, 0x0F, 0xF0, 0x07, 0x78, 0x00, 0xFC, 0x03, 0xE0, 0xE1, 0x1F,
  0xFF, 0x07, 0xF8, 0xC7, 0xFF, 0x03, 0xFE, 0xFF, 0xFF, 0x07, 0xF8, 0x03,
  0xE0, 0x1F, 0x00, 0xFF, 0x00, 0xF8, 0x07, 0xC0, 0xFF, 0x3F, 0xFC, 0xE1,
  0xFF, 0x00, 0xFF, 0xF8, 0x3F, 0xFC, 0xFF, 0xFF, 0xC3, 0xFF, 0x1F, 0xF0,
  0x0F, 0x00, 0x7F, 0x80, 0x3F, 0xC0, 0x03, 0xE0, 0x1F, 0x00, 0x0F, 0xFF,
  0xF8, 0x3F, 0xC0, 0x3F, 0xFE, 0x1F, 0xF0, 0xFF, 0xFF, 0x3F, 0xC0, 0x1F,
  0x00, 0xFF, 0x00, 0xF8, 0x07, 0xC0, 0x3F, 0x00, 0xFE, 0xFF, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x87, 0x07,
  0x00, 0x1C, 0x00, 0xFE, 0xF0, 0x78, 0x00, 0x3C, 0x00, 0x00, 0xC0, 0x3F,
  0xC0, 0x1F, 0xE0, 0x0F, 0x00, 0x7F, 0xC0, 0x3F, 0xE0, 0x1F, 0xE0, 0x0F,
  0xF8, 0x07, 0x78, 0x80, 0x07, 0xC0, 0x03, 0xFE, 0x01, 0xE0, 0x0F, 0x8F,
  0x07, 0xF8, 0x87, 0xFF, 0x3F, 0xE0, 0x1F, 0xE0, 0x0F, 0xF8, 0x07, 0xF8,
  0x03, 0xFC, 0x01, 0x00, 0x8F, 0x07, 0xF8, 0x03, 0xE0, 0x1F, 0x1E, 0x0F,
  0x0F, 0x07, 0x78, 0x38, 0x00, 0xFC, 0x03, 0xFE, 0x01, 0xFF, 0x00, 0x7F,
  0xC0, 0x3F, 0xC0, 0x03, 0x3C, 0x00, 0x1E, 0xF0, 0x0F, 0x00, 0x7F, 0x78,
  0x3C, 0xC0, 0x3F, 0xFC, 0xFF, 0x01, 0xFF, 0x00, 0x7F, 0xC0, 0x3F, 0xC0,
  0x1F, 0xE0, 0x0F, 0x00, 0x78, 0x3C, 0xC0, 0x1F, 0x00, 0xFF, 0xF0, 0x78,
  0x78, 0x38, 0xC0, 0xC3, 0x01, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x87, 0x07, 0x00, 0x1C, 0x00, 0xFE,
  0xF0, 0x78, 0x00, 0x3C, 0x00, 0x00, 0xC0, 0x3F, 0xC0, 0x1F, 0xE0, 0x0F,
  0x00, 0x7F, 0xC0, 0x3F, 0xE0, 0x1F, 0xE0, 0x0F, 0xF8, 0x07, 0x78, 0x80,
  0x07, 0xC0, 0x03, 0xFE, 0x01, 0xE0, 0x0F, 0x8F, 0x07, 0xF8, 0x87, 0xFF,
  0x3F, 0xE0, 0x1F, 0xE0, 0x0F, 0xF8, 0x07, 0xF8, 0x03, 0xFC, 0x01, 0x00,
  0x8F, 0x07, 0xF8, 0x03, 0xE0, 0x1F, 0x1E, 0x0F, 0x0F, 0x07, 0x78, 0x38,
  0x00, 0xFC, 0x03, 0xFE, 0x01, 0xFF, 0x00, 0x7F, 0xC0, 0x3F, 0xC0, 0x03,
  0x3C, 0x00, 0x1E, 0xF0, 0x0F, 0x00, 0x7F, 0x78, 0x3C, 0xC0, 0x3F, 0xFC,
  0xFF, 0x01, 0xFF, 0x00, 0x7F, 0xC0, 0x3F, 0xC0, 0x1F, 0xE0, 0x0F, 0x00,
  0x78, 0x3C, 0xC0, 0x1F, 0x00, 0xFF, 0xF0, 0x78, 0x78, 0x38, 0xC0, 0xC3,
  0x01, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x87, 0x07, 0x00, 0x1C, 0x00, 0xFE, 0xF0, 0x78, 0x00, 0x3C,
  0x00, 0x00, 0xC0, 0x3F, 0xC0, 0x1F, 0xE0, 0x0F, 0x00, 0x7F, 0xC0, 0x3F,
  0xE0, 0x1F, 0xE0, 0x0F, 0xF8, 0x07, 0x78, 0x80, 0x07, 0xC0, 0x03, 0xFE,
  0x01, 0xE0, 0x0F, 0x8F, 0x07, 0xF8, 0x87, 0xFF, 0x3F, 0xE0, 0x1F, 0xE0,
  0x0F, 0xF8, 0x07, 0xF8, 0x03, 0xFC, 0x01, 0x00, 0x8F, 0x07, 0xF8, 0x03,
  0xE0, 0x1F, 0x1E, 0x0F, 0x0F, 0x07, 0x78, 0x38, 0x00, 0xFC, 0x03, 0xFE,
  0x01, 0xFF, 0x00, 0x7F, 0xC0, 0x3F, 0xC0, 0x03, 0x3C, 0x00, 0x1E, 0xF0,
  0x0F, 0x00, 0x7F, 0x78, 0x3C, 0xC0, 0x3F, 0xFC, 0xFF, 0x01, 0xFF, 0x00,
  0x7F, 0xC0, 0x3F, 0xC0, 0x1F, 0xE0, 0x0F, 0x00, 0x78, 0x3C, 0xC0, 0x1F,
  0x00, 0xFF, 0xF0, 0x78, 0x78, 0x38, 0xC0, 0xC3, 0x01, 0xE0, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x87, 0x07,
  0x00, 0x1C, 0x00, 0xFE, 0xF0, 0x78, 0x00, 0x3C, 0x00, 0x00, 0xC0, 0x3F,
  0xC0, 0x1F, 0xE0, 0x0F, 0x00, 0x7F, 0xC0, 0x3F, 0xE0, 0x1F, 0xE0, 0x0F,
  0xF8, 0x07, 0x78, 0x80, 0x07, 0xC0, 0x03, 0xFE, 0x01, 0xE0, 0x0F, 0x8F,
  0x07, 0xF8, 0x87, 0xFF, 0x3F, 0xE0, 0x1F, 0xE0, 0x0F, 0xF8, 0x07, 0xF8,
  0x03, 0xFC, 0x01, 0x00, 0x8F, 0x07, 0x38, 0x00, 0x00, 0x1E, 0x1E, 0x0F,
  0x0F, 0x07, 0x78, 0x38, 0x00, 0xFC, 0x03, 0xFE, 0x01, 0xFF, 0x00, 0x7F,
  0xC0, 0x3F, 0xC0, 0x03, 0x3C, 0x00, 0x1E, 0xF0, 0x0F, 0x00, 0x7F, 0x78,
  0x3C, 0xC0, 0x3F, 0xFC, 0xFF, 0x01, 0xFF, 0x00, 0x7F, 0xC0, 0x3F, 0xC0,
  0x1F, 0xE0, 0x0F, 0x00, 0x78, 0x3C, 0xC0, 0x01, 0x00, 0xF0, 0xF0, 0x78,
  0x78, 0x38, 0xC0, 0xC3, 0x01, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x87, 0x07, 0xFC, 0x03, 0xFE, 0xF1,
  0xF0, 0xF8, 0x7F, 0xFC, 0x3F, 0x00, 0x3C, 0xC0, 0x3F, 0xE0, 0xFF, 0x00,
  0xFF, 0xF8, 0xFF, 0xFF, 0x1F, 0x1E, 0x00, 0x0F, 0xF8, 0xFF, 0xFF, 0xFF,
  0x87, 0xFF, 0xFF, 0xFF, 0x01, 0xE0, 0xFF, 0x80, 0x07, 0x78, 0x78, 0xFC,
  0xC3, 0xE3, 0x1F, 0xE0, 0xFF, 0x87, 0x07, 0xF8, 0xFF, 0x03, 0xFE, 0x00,
  0x8F, 0x07, 0x38, 0x3C, 0x1C, 0x1E, 0x1E, 0x0F, 0xF0, 0x00, 0x80, 0x07,
  0xC0, 0xC3, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x78, 0xC0, 0xFF, 0xFF, 0xFF,
  0x3F, 0xFC, 0xFF, 0xFF, 0x0F, 0x00, 0xFF, 0x07, 0x3C, 0xC0, 0xC3, 0xE3,
  0x1F, 0x1E, 0xFF, 0x00, 0xFF, 0x3F, 0x3C, 0xC0, 0xFF, 0x1F, 0xF0, 0x07,
  0x78, 0x3C, 0xC0, 0xE1, 0xE1, 0xF0, 0xF0, 0x78, 0x80, 0x07, 0x00, 0x3C,
  0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x87, 0x07, 0xFC, 0x03, 0xFE, 0xF1, 0xF0, 0xF8, 0x7F, 0xFC,
  0x3F, 0x00, 0x3C, 0xC0, 0x3F, 0xE0, 0xFF, 0x00, 0xFF, 0xF8, 0xFF, 0xFF,
  0x1F, 0x1E, 0x00, 0x0F, 0xF8, 0xFF, 0xFF, 0xFF, 0x87, 0xFF, 0xFF, 0xFF,
  0x01, 0xE0, 0xFF, 0x80, 0x07, 0x78, 0x78, 0xFC, 0xC3, 0xE3, 0x1F, 0xE0,
  0xFF, 0x87, 0x07, 0xF8, 0xFF, 0x03, 0xFE, 0x00, 0x8F, 0x07, 0x38, 0x3C,
  0x1C, 0x1E, 0x1E, 0x0F, 0xF0, 0x00, 0x80, 0x07, 0xC0, 0xC3, 0xFF, 0xFF,
  0xFF, 0xF0, 0x00, 0x78, 0xC0, 0xFF, 0xFF, 0xFF, 0x3F, 0xFC, 0xFF, 0xFF,
  0x0F, 0x00, 0xFF, 0x07, 0x3C, 0xC0, 0xC3, 0xE3, 0x1F, 0x1E, 0xFF, 0x00,
  0xFF, 0x3F, 0x3C, 0xC0, 0xFF, 0x1F, 0xF0, 0x07, 0x78, 0x3C, 0xC0, 0xE1,
  0xE1, 0xF0, 0xF0, 0x78, 0x80, 0x07, 0x00, 0x3C, 0x00, 0x1E, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x87, 0x07,
  0xFC, 0x03, 0xFE, 0xF1, 0xF0, 0xF8, 0x7F, 0xFC, 0x3F, 0x00, 0x3C, 0xC0,
  0x3F, 0xE0, 0xFF, 0x00, 0xFF, 0xF8, 0xFF, 0xFF, 0x1F, 0x1E, 0x00, 0x0F,
  0xF8, 0xFF, 0xFF, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0x01, 0xE0, 0xFF, 0x80,
  0x07, 0x78, 0x78, 0xFC, 0xC3, 0xE3, 0x1F, 0xE0, 0xFF, 0x87, 0x07, 0xF8,
  0xFF, 0x03, 0xFE, 0x00, 0x8F, 0x07, 0x38, 0x3C, 0x1C, 0x1E, 0x1E, 0x0F,
  0xF0, 0x00, 0x80, 0x07, 0xC0, 0xC3, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x78,
  0xC0, 0xFF, 0xFF, 0xFF, 0x3F, 0xFC, 0xFF, 0xFF, 0x0F, 0x00, 0xFF, 0x07,
  0x3C, 0xC0, 0xC3, 0xE3, 0x1F, 0x1E, 0xFF, 0x00, 0xFF, 0x3F, 0x3C, 0xC0,
  0xFF, 0x1F, 0xF0, 0x07, 0x78, 0x3C, 0xC0, 0xE1, 0xE1, 0xF0, 0xF0, 0x78,
  0x80, 0x07, 0x00, 0x3C, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x87, 0xC7, 0x03, 0x00, 0x00, 0xFE,
  0xFF, 0xFF, 0x7F, 0x3C, 0xC0, 0x03, 0x3C, 0x3C, 0xC0, 0x01, 0xE0, 0x0F,
  0xFF, 0xF8, 0xFF, 0x3F, 0xE0, 0x1F, 0xE0, 0x0F, 0xF8, 0xFF, 0xFF, 0xFF,
  0x87, 0xFF, 0xFF, 0xFF, 0x1F, 0xE0, 0x0F, 0x8F, 0x07, 0x78, 0x78, 0xFC,
  0x03, 0xFC, 0x1F, 0xE0, 0xFF, 0x87, 0x07, 0xF8, 0xC3, 0x03, 0x00, 0x0F,
  0x8F, 0x07, 0x38, 0x3C, 0x1C, 0x1E, 0x1E, 0x0F, 0x0F, 0x07, 0x80, 0x07,
  0x3C, 0xC0, 0xFF, 0xFF, 0x01, 0xFF, 0x00, 0x7F, 0xC0, 0xFF, 0xFF, 0xFF,
  0x3F, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0x78, 0x3C, 0xC0, 0xC3, 0xE3,
  0x1F, 0xE0, 0xFF, 0x00, 0xFF, 0x3F, 0x3C, 0xC0, 0x1F, 0x1E, 0x00, 0x78,
  0x78, 0x3C, 0xC0, 0xE1, 0xE1, 0xF0, 0xF0, 0x78, 0x78, 0x38, 0x00, 0x3C,
  0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x87, 0xC7, 0x03, 0x00, 0x00, 0xFE, 0xFF, 0x07, 0xC0, 0x3F,
  0xC0, 0xC3, 0x03, 0x3C, 0xC0, 0x01, 0xE0, 0x0F, 0x00, 0x78, 0xC0, 0x3F,
  0xE0, 0x1F, 0xE0, 0x0F, 0xF8, 0x07, 0x78, 0x80, 0x07, 0xF8, 0x03, 0xFE,
  0x1F, 0xE0, 0x0F, 0x8F, 0x07, 0x78, 0x00, 0xFC, 0x03, 0xFC, 0x1F, 0xE0,
  0x0F, 0x80, 0x07, 0xF8, 0xC3, 0x03, 0x00, 0x0F, 0x8F, 0x07, 0x38, 0x3C,
  0x1C, 0x1E, 0x1E, 0x0F, 0x0F, 0x07, 0x80, 0x07, 0x3C, 0xC0, 0x03, 0xFE,
  0x01, 0xFF, 0x00, 0x7F, 0xC0, 0x3F, 0xC0, 0x03, 0x3C, 0xC0, 0x1F, 0xF0,
  0xFF, 0x00, 0x7F, 0x78, 0x3C, 0xC0, 0x03, 0xE0, 0x1F, 0xE0, 0xFF, 0x00,
  0x7F, 0x00, 0x3C, 0xC0, 0x1F, 0x1E, 0x00, 0x78, 0x78, 0x3C, 0xC0, 0xE1,
  0xE1, 0xF0, 0xF0, 0x78, 0x78, 0x38, 0x00, 0x3C, 0xE0, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x87, 0xC7,
  0x03, 0x00, 0x00, 0xFE, 0xFF, 0x07, 0xC0, 0x3F, 0xC0, 0xC3, 0x03, 0x3C,
  0xC0, 0x01, 0xE0, 0x0F, 0x00, 0x78, 0xC0, 0x3F, 0xE0, 0x1F, 0xE0, 0x0F,
  0xF8, 0x07, 0x78, 0x80, 0x07, 0xF8, 0x03, 0xFE, 0x1F, 0xE0, 0x0F, 0x8F,
  0x07, 0x78, 0x00, 0xFC, 0x03, 0xFC, 0x1F, 0xE0, 0x0F, 0x80, 0x07, 0xF8,
  0xC3, 0x03, 0x00, 0x0F, 0x8F, 0x07, 0x38, 0x3C, 0x1C, 0x1E, 0x1E, 0x0F,
  0x0F, 0x07, 0x80, 0x07, 0x3C, 0xC0, 0x03, 0xFE, 0x01, 0xFF, 0x00, 0x7F,
  0xC0, 0x3F, 0xC0, 0x03, 0x3C, 0xC0, 0x1F, 0xF0, 0xFF, 0x00, 0x7F, 0x78,
  0x3C, 0xC0, 0x03, 0xE0, 0x1F, 0xE0, 0xFF, 0x00, 0x7F, 0x00, 0x3C, 0xC0,
  0x1F, 0x1E, 0x00, 0x78, 0x78, 0x3C, 0xC0, 0xE1, 0xE1, 0xF0, 0xF0, 0x78,
  0x78, 0x38, 0x00, 0x3C, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x87, 0xC7, 0x03, 0x00, 0x00, 0xFE,
  0xFF, 0x07, 0xC0, 0x3F, 0xC0, 0xC3, 0x03, 0x3C, 0xC0, 0x01, 0xE0, 0x0F,
  0x00, 0x78, 0xC0, 0x3F, 0xE0, 0x1F, 0xE0, 0x0F, 0xF8, 0x07, 0x78, 0x80,
  0x07, 0xF8, 0x03, 0xFE, 0x1F, 0xE0, 0x0F, 0x8F, 0x07, 0x78, 0x00, 0xFC,
  0x03, 0xFC, 0x1F, 0xE0, 0x0F, 0x80, 0x07, 0xF8, 0xC3, 0x03, 0x00, 0x0F,
  0x8F, 0x07, 0x38, 0x3C, 0x1C, 0x1E, 0x1E, 0x0F, 0x0F, 0x07, 0x80, 0x07,
  0x3C, 0xC0, 0x03, 0xFE, 0x01, 0xFF, 0x00, 0x7F, 0xC0, 0x3F, 0xC0, 0x03,
  0x3C, 0xC0, 0x1F, 0xF0, 0xFF, 0x00, 0x7F, 0x78, 0x3C, 0xC0, 0x03, 0xE0,
  0x1F, 0xE0, 0xFF, 0x00, 0x7F, 0x00, 0x3C, 0xC0, 0x1F, 0x1E, 0x00, 0x78,
  0x78, 0x3C, 0xC0, 0xE1, 0xE1, 0xF0, 0xF0, 0x78, 0x78, 0x38, 0x00, 0x3C,
  0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xF0, 0xF8, 0xFF, 0xC3,
  0x3F, 0xC0, 0x03, 0xC0, 0x3F, 0xE0, 0x1F, 0x00, 0x0F, 0x78, 0xC0, 0xFF,
  0x1F, 0xE0, 0x1F, 0xFF, 0x87, 0xFF, 0x7F, 0x00, 0xF8, 0xC7, 0x03, 0xFE,
  0xE1, 0x1F, 0x0F, 0xF0, 0xFF, 0x7F, 0x00, 0xFC, 0x03, 0xE0, 0xE1, 0x1F,
  0x0F, 0x00, 0xF8, 0xC7, 0x03, 0xFC, 0xFF, 0x00, 0x0F, 0xF8, 0x07, 0xC0,
  0x03, 0xE0, 0xE1, 0xF0, 0x00, 0x78, 0x80, 0x07, 0xFC, 0xFF, 0x03, 0xFE,
  0xFF, 0x00, 0xFF, 0xF8, 0x3F, 0xFC, 0xFF, 0x03, 0xC0, 0x3F, 0x1E, 0xF0,
  0x0F, 0xFF, 0x78, 0x80, 0xFF, 0xFF, 0x03, 0xE0, 0x1F, 0x00, 0x0F, 0xFF,
  0x78, 0x00, 0xC0, 0x3F, 0x1E, 0xE0, 0xFF, 0x07, 0x78, 0xC0, 0x3F, 0x00,
  0x1E, 0x00, 0x0F, 0x87, 0x07, 0xC0, 0x03, 0x3C, 0xE0, 0xFF, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xF8, 0xFF,
  0xFF, 0xFF, 0xFF, 0x01, 0xF0, 0xF8, 0x7F, 0xC0, 0x3F, 0xC0, 0x03, 0xC0,
  0x3F, 0xE0, 0x1F, 0x00, 0x0F, 0x78, 0xC0, 0xFF, 0x1F, 0xE0, 0x1F, 0xFF,
  0x87, 0xFF, 0x7F, 0x00, 0xF8, 0xC7, 0x03, 0xFE, 0xE1, 0x1F, 0x0F, 0xF0,
  0xFF, 0x7F, 0x00, 0xFC, 0x03, 0xE0, 0xE1, 0x1F, 0x0F, 0x00, 0xF8, 0xC7,
  0x03, 0xFC, 0xFF, 0x00, 0x0F, 0xF8, 0x07, 0xC0, 0x03, 0xE0, 0xE1, 0xF0,
  0x00, 0x78, 0x80, 0x07, 0xFC, 0xFF, 0x03, 0xFE, 0xFF, 0x00, 0xFF, 0xF8,
  0x3F, 0xFC, 0xFF, 0x03, 0xC0, 0x3F, 0x1E, 0xF0, 0x0F, 0xFF, 0x78, 0x80,
  0xFF, 0xFF, 0x03, 0xE0, 0x1F, 0x00, 0x0F, 0xFF, 0x78, 0x00, 0xC0, 0x3F,
  0x1E, 0xE0, 0xFF, 0x07, 0x78, 0xC0, 0x3F, 0x00, 0x1E, 0x00, 0x0F, 0x87,
  0x07, 0xC0, 0x03, 0x3C, 0xE0, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x01,
  0xF0, 0xF8, 0x7F, 0xC0, 0x3F, 0xC0, 0x03, 0xC0, 0x3F, 0xE0, 0x1F, 0x00,
  0x0F, 0x78, 0xC0, 0xFF, 0x1F, 0xE0, 0x1F, 0xFF, 0x87, 0xFF, 0x7F, 0x00,
  0xF8, 0xC7, 0x03, 0xFE, 0xE1, 0x1F, 0x0F, 0xF0, 0xFF, 0x7F, 0x00, 0xFC,
  0x03, 0xE0, 0xE1, 0x1F, 0x0F, 0x00, 0xF8, 0xC7, 0x03, 0xFC, 0xFF, 0x00,
  0x0F, 0xF8, 0x07, 0xC0, 0x03, 0xE0, 0xE1, 0xF0, 0x00, 0x78, 0x80, 0x07,
  0xFC, 0xFF, 0x03, 0xFE, 0xFF, 0x00, 0xFF, 0xF8, 0x3F, 0xFC, 0xFF, 0x03,
  0xC0, 0x3F, 0x1E, 0xF0, 0x0F, 0xFF, 0x78, 0x80, 0xFF, 0xFF, 0x03, 0xE0,
  0x1F, 0x00, 0x0F, 0xFF, 0x78, 0x00, 0xC0, 0x3F, 0x1E, 0xE0, 0xFF, 0x07,
  0x78, 0xC0, 0x3F, 0x00, 0x1E, 0x00, 0x0F, 0x87, 0x07, 0xC0, 0x03, 0x3C,
  0xE0, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xF0, 0xF8, 0x7F, 0xC0,
  0x3F, 0xC0, 0x03, 0xC0, 0x3F, 0xE0, 0x1F, 0x00, 0x0F, 0x78, 0xC0, 0xFF,
  0x1F, 0xE0, 0x1F, 0xFF, 0x87, 0xFF, 0x7F, 0x00, 0xF8, 0xC7, 0x03, 0xFE,
  0xE1, 0x1F, 0x0F, 0xF0, 0xFF, 0x7F, 0x00, 0xFC, 0x03, 0xE0, 0xE1, 0x1F,
  0x0F, 0x00, 0xF8, 0xC7, 0x03, 0xFC, 0xFF, 0x00, 0x0F, 0xF8, 0x07, 0xC0,
  0x03, 0xE0, 0xE1, 0xF0, 0x00, 0x78, 0x80, 0x07, 0xFC, 0xFF, 0x03, 0xFE,
  0xFF, 0x00, 0xFF, 0xF8, 0x3F, 0xFC, 0xFF, 0x03, 0xC0, 0x3F, 0x1E, 0xF0,
  0x0F, 0xFF, 0x78, 0x80, 0xFF, 0xFF, 0x03, 0xE0, 0x1F, 0x00, 0x0F, 0xFF,
  0x78, 0x00, 0xC0, 0x3F, 0x1E, 0xE0, 0xFF, 0x07, 0x78, 0xC0, 0x3F, 0x00,
  0x1E, 0x00, 0x0F, 0x87, 0x07, 0xC0, 0x03, 0x3C, 0xE0, 0xFF, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00,
  },
  23
};
}