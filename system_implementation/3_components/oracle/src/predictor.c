#include "predictor.h"

float predict_margin(union Entry* data) {
  float sum = 0.0f;
  if (!(data[37].missing != -1) || data[37].fvalue < 0.100007) {
    sum += (float)-0.599989;
  } else {
    sum += (float)-0.597457;
  }
  if (!(data[28].missing != -1) || data[28].fvalue < 0.0107208) {
    sum += (float)-0.419684;
  } else {
    sum += (float)-0.416714;
  }
  if (!(data[37].missing != -1) || data[37].fvalue < 0.0738133) {
    sum += (float)-0.294097;
  } else {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0137233) {
      sum += (float)-0.292864;
    } else {
      sum += (float)-0.290432;
    }
  }
  if (!(data[37].missing != -1) || data[37].fvalue < 0.0912334) {
    sum += (float)-0.205868;
  } else {
    if (!(data[19].missing != -1) || data[19].fvalue < 0.0108) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.199732) {
        sum += (float)-0.205057;
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.266756) {
          if (!(data[4].missing != -1) || data[4].fvalue < 0.00234455) {
            sum += (float)0.0155296;
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0508874) {
              sum += (float)-0.0371981;
            } else {
              sum += (float)-0.0100937;
            }
          }
        } else {
          sum += (float)-0.183106;
        }
      }
    } else {
      sum += (float)-0.203338;
    }
  }
  if (!(data[10].missing != -1) || data[10].fvalue < 0.00617207) {
    sum += (float)-0.144002;
  } else {
    sum += (float)-0.142949;
  }
  if (!(data[37].missing != -1) || data[37].fvalue < 0.0539453) {
    sum += (float)-0.100915;
  } else {
    if (!(data[19].missing != -1) || data[19].fvalue < 1.91758e-06) {
      if (!(data[23].missing != -1) || data[23].fvalue < 0.000130766) {
        sum += (float)-0.0495228;
      } else {
        sum += (float)-0.0950438;
      }
    } else {
      if (!(data[1].missing != -1) || data[1].fvalue < 0.0186291) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.199732) {
          if (!(data[26].missing != -1) || data[26].fvalue < 2.55558e-08) {
            sum += (float)-0.100367;
          } else {
            sum += (float)-0.101255;
          }
        } else {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.257373) {
            if (!(data[4].missing != -1) || data[4].fvalue < 0.0224351) {
              sum += (float)0.0273699;
            } else {
              sum += (float)-0.00835585;
            }
          } else {
            sum += (float)-0.0949945;
          }
        }
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0603217) {
          sum += (float)-0.0990789;
        } else {
          if (!(data[43].missing != -1) || data[43].fvalue < 1.60011e-09) {
            sum += (float)0.00514024;
          } else {
            sum += (float)-0.0764282;
          }
        }
      }
    }
  }
  if (!(data[19].missing != -1) || data[19].fvalue < 0.0160796) {
    if (!(data[37].missing != -1) || data[37].fvalue < 0.0296219) {
      sum += (float)-0.0706393;
    } else {
      if (!(data[19].missing != -1) || data[19].fvalue < 2.20393e-06) {
        if (!(data[33].missing != -1) || data[33].fvalue < 0.000226247) {
          if (!(data[39].missing != -1) || data[39].fvalue < 0.00260206) {
            sum += (float)-0.0664512;
          } else {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.00516995) {
              sum += (float)-0.0389659;
            } else {
              sum += (float)-0.0219046;
            }
          }
        } else {
          sum += (float)-0.0676555;
        }
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.199732) {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.35381e-08) {
            sum += (float)-0.0702781;
          } else {
            sum += (float)-0.0709393;
          }
        } else {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.266756) {
            if (!(data[4].missing != -1) || data[4].fvalue < 0.00830241) {
              sum += (float)0.0264067;
            } else {
              sum += (float)-0.00285949;
            }
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0344903) {
              sum += (float)-0.0176698;
            } else {
              sum += (float)-0.0693437;
            }
          }
        }
      }
    }
  } else {
    sum += (float)-0.0695035;
  }
  if (!(data[1].missing != -1) || data[1].fvalue < 0.0115511) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.075068) {
      if (!(data[37].missing != -1) || data[37].fvalue < 0.0982019) {
        sum += (float)-0.0494461;
      } else {
        if (!(data[20].missing != -1) || data[20].fvalue < 8.22136e-05) {
          if (!(data[26].missing != -1) || data[26].fvalue < 6.61321e-09) {
            if (!(data[23].missing != -1) || data[23].fvalue < 0.000125414) {
              sum += (float)-0.0102533;
            } else {
              sum += (float)-0.0493537;
            }
          } else {
            if (!(data[23].missing != -1) || data[23].fvalue < 0.000158615) {
              sum += (float)-0.029975;
            } else {
              sum += (float)-0.0458763;
            }
          }
        } else {
          if (!(data[24].missing != -1) || data[24].fvalue < 0.000150281) {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.00294221) {
              sum += (float)-0.047179;
            } else {
              sum += (float)-0.0107227;
            }
          } else {
            if (!(data[14].missing != -1) || data[14].fvalue < 0.40191) {
              sum += (float)-0.0492799;
            } else {
              sum += (float)-0.0464567;
            }
          }
        }
      }
    } else {
      if (!(data[4].missing != -1) || data[4].fvalue < 0.412564) {
        if (!(data[35].missing != -1) || data[35].fvalue < 2.70001e-10) {
          if (!(data[33].missing != -1) || data[33].fvalue < 0.0344711) {
            if (!(data[17].missing != -1) || data[17].fvalue < 2.42805e-10) {
              sum += (float)-0.0301349;
            } else {
              sum += (float)0.0434039;
            }
          } else {
            if (!(data[8].missing != -1) || data[8].fvalue < 1.95436e-10) {
              sum += (float)-0.00624668;
            } else {
              sum += (float)-0.0467861;
            }
          }
        } else {
          sum += (float)-0.0481456;
        }
      } else {
        sum += (float)0.0418809;
      }
    }
  } else {
    if (!(data[37].missing != -1) || data[37].fvalue < 0.100007) {
      sum += (float)-0.0499746;
    } else {
      if (!(data[19].missing != -1) || data[19].fvalue < 0.292225) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0603217) {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.00527398) {
            sum += (float)-0.0469114;
          } else {
            sum += (float)-0.0486325;
          }
        } else {
          if (!(data[43].missing != -1) || data[43].fvalue < 1.58673e-09) {
            sum += (float)0.0147947;
          } else {
            if (!(data[10].missing != -1) || data[10].fvalue < 0.0536193) {
              sum += (float)-0.0422124;
            } else {
              sum += (float)-0.0259366;
            }
          }
        }
      } else {
        if (!(data[1].missing != -1) || data[1].fvalue < 0.0147453) {
          sum += (float)0.0418809;
        } else {
          sum += (float)-0.0381167;
        }
      }
    }
  }
  if (!(data[19].missing != -1) || data[19].fvalue < 0.00536387) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0951743) {
      sum += (float)-0.0345906;
    } else {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0978552) {
        if (!(data[0].missing != -1) || data[0].fvalue < 0.157233) {
          sum += (float)0.0527923;
        } else {
          sum += (float)-0.0179257;
        }
      } else {
        if (!(data[35].missing != -1) || data[35].fvalue < 2.70001e-10) {
          if (!(data[6].missing != -1) || data[6].fvalue < 0.0022462) {
            sum += (float)0.0331275;
          } else {
            if (!(data[5].missing != -1) || data[5].fvalue < 0.00034158) {
              sum += (float)-0.00321658;
            } else {
              sum += (float)-0.0308814;
            }
          }
        } else {
          sum += (float)-0.0335612;
        }
      }
    }
  } else {
    if (!(data[37].missing != -1) || data[37].fvalue < 0.100007) {
      sum += (float)-0.0350292;
    } else {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.00516943) {
        if (!(data[35].missing != -1) || data[35].fvalue < 4.78244e-09) {
          sum += (float)-0.0332817;
        } else {
          sum += (float)-0.0298854;
        }
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0174263) {
          sum += (float)-0.0343282;
        } else {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.104558) {
            sum += (float)-0.0338734;
          } else {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.0201072) {
              sum += (float)0.0355988;
            } else {
              sum += (float)-0.0283341;
            }
          }
        }
      }
    }
  }
  if (!(data[1].missing != -1) || data[1].fvalue < 0.00544335) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0737265) {
      if (!(data[19].missing != -1) || data[19].fvalue < 0.164879) {
        if (!(data[35].missing != -1) || data[35].fvalue < 1.44861e-08) {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0195165) {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.0106735) {
              sum += (float)-0.0242293;
            } else {
              sum += (float)-0.025187;
            }
          } else {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.000247649) {
              sum += (float)-0.0229427;
            } else {
              sum += (float)-0.0241856;
            }
          }
        } else {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0998924) {
            sum += (float)-0.0242294;
          } else {
            if (!(data[33].missing != -1) || data[33].fvalue < 0.000150894) {
              sum += (float)-0.0127128;
            } else {
              sum += (float)-0.0246298;
            }
          }
        }
      } else {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.16756) {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.169912) {
            sum += (float)0.0602162;
          } else {
            sum += (float)-0.0130176;
          }
        } else {
          sum += (float)-0.0225657;
        }
      }
    } else {
      if (!(data[4].missing != -1) || data[4].fvalue < 0.412564) {
        if (!(data[35].missing != -1) || data[35].fvalue < 2.0176e-10) {
          if (!(data[3].missing != -1) || data[3].fvalue < 4.5) {
            sum += (float)0.0448735;
          } else {
            if (!(data[35].missing != -1) || data[35].fvalue < 1.99817e-10) {
              sum += (float)-0.0168999;
            } else {
              sum += (float)0.0024789;
            }
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.0335392) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0330299) {
              sum += (float)-0.0173859;
            } else {
              sum += (float)-0.000829906;
            }
          } else {
            if (!(data[35].missing != -1) || data[35].fvalue < 2.70001e-10) {
              sum += (float)-0.0172777;
            } else {
              sum += (float)-0.0243156;
            }
          }
        }
      } else {
        sum += (float)0.0406798;
      }
    }
  } else {
    if (!(data[37].missing != -1) || data[37].fvalue < 0.100007) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0107208) {
        sum += (float)-0.0243011;
      } else {
        sum += (float)-0.0252232;
      }
    } else {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0053036) {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.00531581) {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.0437e-10) {
            if (!(data[1].missing != -1) || data[1].fvalue < 0.0537424) {
              sum += (float)-0.0233653;
            } else {
              sum += (float)-5.31971e-06;
            }
          } else {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.0300382) {
              sum += (float)-0.0218679;
            } else {
              sum += (float)-0.0196815;
            }
          }
        } else {
          if (!(data[35].missing != -1) || data[35].fvalue < 7.74964e-09) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0330673) {
              sum += (float)-0.00496123;
            } else {
              sum += (float)-0.0234171;
            }
          } else {
            sum += (float)-0.0205219;
          }
        }
      } else {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.0455781) {
          if (!(data[43].missing != -1) || data[43].fvalue < 1.92602e-09) {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.0603217) {
              sum += (float)-0.0240487;
            } else {
              sum += (float)-0.00481858;
            }
          } else {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.00272228) {
              sum += (float)-0.0225271;
            } else {
              sum += (float)-0.0237534;
            }
          }
        } else {
          if (!(data[35].missing != -1) || data[35].fvalue < 1.16282e-09) {
            sum += (float)0.00299116;
          } else {
            if (!(data[5].missing != -1) || data[5].fvalue < 0.00145094) {
              sum += (float)-0.0165863;
            } else {
              sum += (float)-0.0232786;
            }
          }
        }
      }
    }
  }
  if (!(data[10].missing != -1) || data[10].fvalue < 0.0187654) {
    if (!(data[19].missing != -1) || data[19].fvalue < 0.00536387) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0951743) {
        if (!(data[43].missing != -1) || data[43].fvalue < 1.71194e-08) {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0412512) {
            sum += (float)-0.0169644;
          } else {
            if (!(data[10].missing != -1) || data[10].fvalue < 0.00083277) {
              sum += (float)-0.0160382;
            } else {
              sum += (float)-0.016939;
            }
          }
        } else {
          if (!(data[20].missing != -1) || data[20].fvalue < 0.099957) {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.00268639) {
              sum += (float)-0.0169644;
            } else {
              sum += (float)-0.0162012;
            }
          } else {
            if (!(data[27].missing != -1) || data[27].fvalue < 0.0410171) {
              sum += (float)-0.0130691;
            } else {
              sum += (float)-0.0172534;
            }
          }
        }
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0978552) {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.157233) {
            sum += (float)0.0381425;
          } else {
            sum += (float)-0.0115895;
          }
        } else {
          if (!(data[43].missing != -1) || data[43].fvalue < 8.06187e-09) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.00269004) {
              sum += (float)-0.016336;
            } else {
              sum += (float)-0.000249497;
            }
          } else {
            if (!(data[1].missing != -1) || data[1].fvalue < 2.07098e-06) {
              sum += (float)-0.00468871;
            } else {
              sum += (float)-0.0218485;
            }
          }
        }
      }
    } else {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.00985376) {
        if (!(data[10].missing != -1) || data[10].fvalue < 3.68686e-06) {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0995038) {
            sum += (float)-0.0168117;
          } else {
            if (!(data[26].missing != -1) || data[26].fvalue < 1.61882e-12) {
              sum += (float)-0.0134961;
            } else {
              sum += (float)-0.0161058;
            }
          }
        } else {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.164879) {
            if (!(data[8].missing != -1) || data[8].fvalue < 0.000186474) {
              sum += (float)-0.016755;
            } else {
              sum += (float)-0.00190677;
            }
          } else {
            if (!(data[4].missing != -1) || data[4].fvalue < 0.063836) {
              sum += (float)-0.0164582;
            } else {
              sum += (float)0.0511838;
            }
          }
        }
      } else {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.0455774) {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0993497) {
            sum += (float)-0.0175726;
          } else {
            if (!(data[31].missing != -1) || data[31].fvalue < 0.00151309) {
              sum += (float)-0.0151697;
            } else {
              sum += (float)-0.0169455;
            }
          }
        } else {
          if (!(data[35].missing != -1) || data[35].fvalue < 1.24608e-09) {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.0335121) {
              sum += (float)-0.00993961;
            } else {
              sum += (float)0.0047338;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 4.00095e-10) {
              sum += (float)-0.00993288;
            } else {
              sum += (float)-0.0165;
            }
          }
        }
      }
    }
  } else {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0603217) {
      if (!(data[37].missing != -1) || data[37].fvalue < 0.099957) {
        sum += (float)-0.0175217;
      } else {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.565684) {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.00495248) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0329883) {
              sum += (float)-0.00421705;
            } else {
              sum += (float)-0.0158727;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 9.83403e-06) {
              sum += (float)-0.0165643;
            } else {
              sum += (float)-0.00365886;
            }
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.0425956) {
            sum += (float)-0.00851005;
          } else {
            sum += (float)0.000607584;
          }
        }
      }
    } else {
      if (!(data[8].missing != -1) || data[8].fvalue < 1.02658e-08) {
        if (!(data[7].missing != -1) || data[7].fvalue < 0.540204) {
          if (!(data[5].missing != -1) || data[5].fvalue < 0.000243853) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0330775) {
              sum += (float)0.00361137;
            } else {
              sum += (float)0.000534533;
            }
          } else {
            sum += (float)-0.0181788;
          }
        } else {
          if (!(data[8].missing != -1) || data[8].fvalue < 1.75734e-09) {
            if (!(data[7].missing != -1) || data[7].fvalue < 0.654768) {
              sum += (float)0.0192776;
            } else {
              sum += (float)-0.00949387;
            }
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.102228) {
              sum += (float)-0.00134949;
            } else {
              sum += (float)-0.0144155;
            }
          }
        }
      } else {
        sum += (float)0.0345778;
      }
    }
  }
  if (!(data[1].missing != -1) || data[1].fvalue < 0.00819102) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0348535) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0106863) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.00544374) {
          if (!(data[17].missing != -1) || data[17].fvalue < 2.75558e-10) {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.0981874) {
              sum += (float)-0.0118702;
            } else {
              sum += (float)-0.0116852;
            }
          } else {
            if (!(data[11].missing != -1) || data[11].fvalue < 0.099336) {
              sum += (float)-0.0118636;
            } else {
              sum += (float)-0.011939;
            }
          }
        } else {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.164879) {
            if (!(data[43].missing != -1) || data[43].fvalue < 4.19361e-09) {
              sum += (float)-0.0116904;
            } else {
              sum += (float)-0.0103742;
            }
          } else {
            if (!(data[4].missing != -1) || data[4].fvalue < 0.063836) {
              sum += (float)-0.00986515;
            } else {
              sum += (float)0.0435062;
            }
          }
        }
      } else {
        if (!(data[31].missing != -1) || data[31].fvalue < 0.000830636) {
          if (!(data[39].missing != -1) || data[39].fvalue < 0.00193311) {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.00132751) {
              sum += (float)-0.0130729;
            } else {
              sum += (float)-0.00785577;
            }
          } else {
            if (!(data[32].missing != -1) || data[32].fvalue < 0.00330544) {
              sum += (float)0.0136074;
            } else {
              sum += (float)-0.00385461;
            }
          }
        } else {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.008154) {
            if (!(data[14].missing != -1) || data[14].fvalue < 0.11638) {
              sum += (float)-0.0123533;
            } else {
              sum += (float)-0.0116337;
            }
          } else {
            if (!(data[10].missing != -1) || data[10].fvalue < 0.0428964) {
              sum += (float)-0.0118801;
            } else {
              sum += (float)-0.00938317;
            }
          }
        }
      }
    } else {
      if (!(data[36].missing != -1) || data[36].fvalue < 0.0363744) {
        if (!(data[0].missing != -1) || data[0].fvalue < 0.0363151) {
          if (!(data[26].missing != -1) || data[26].fvalue < 1.88066e-10) {
            sum += (float)0.00878427;
          } else {
            if (!(data[17].missing != -1) || data[17].fvalue < 1.43713e-09) {
              sum += (float)-0.0136269;
            } else {
              sum += (float)-0.0042188;
            }
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.036349) {
            sum += (float)0.116658;
          } else {
            sum += (float)0.0178833;
          }
        }
      } else {
        if (!(data[31].missing != -1) || data[31].fvalue < 0.493017) {
          if (!(data[32].missing != -1) || data[32].fvalue < 0.00108754) {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.0466825) {
              sum += (float)-0.0111188;
            } else {
              sum += (float)0.00321708;
            }
          } else {
            if (!(data[10].missing != -1) || data[10].fvalue < 0.357909) {
              sum += (float)-0.0122016;
            } else {
              sum += (float)-0.000580176;
            }
          }
        } else {
          if (!(data[10].missing != -1) || data[10].fvalue < 0.0187668) {
            if (!(data[1].missing != -1) || data[1].fvalue < 0.00269382) {
              sum += (float)-0.0101755;
            } else {
              sum += (float)0.00317506;
            }
          } else {
            sum += (float)0.0293911;
          }
        }
      }
    }
  } else {
    if (!(data[37].missing != -1) || data[37].fvalue < 0.100007) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0107208) {
        sum += (float)-0.0119285;
      } else {
        sum += (float)-0.0124374;
      }
    } else {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0053036) {
        if (!(data[35].missing != -1) || data[35].fvalue < 3.97653e-09) {
          if (!(data[31].missing != -1) || data[31].fvalue < 1.57926e-05) {
            if (!(data[31].missing != -1) || data[31].fvalue < 1.54013e-05) {
              sum += (float)-0.0103913;
            } else {
              sum += (float)0.0406881;
            }
          } else {
            if (!(data[40].missing != -1) || data[40].fvalue < 0.314229) {
              sum += (float)-0.0114262;
            } else {
              sum += (float)-0.00990601;
            }
          }
        } else {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.12755e-10) {
            if (!(data[1].missing != -1) || data[1].fvalue < 0.0537424) {
              sum += (float)-0.0116154;
            } else {
              sum += (float)0.00253634;
            }
          } else {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.0204914) {
              sum += (float)-0.0101924;
            } else {
              sum += (float)-0.00816561;
            }
          }
        }
      } else {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.292225) {
          if (!(data[39].missing != -1) || data[39].fvalue < 0.00676794) {
            if (!(data[9].missing != -1) || data[9].fvalue < 0.032643) {
              sum += (float)0.0012404;
            } else {
              sum += (float)-0.012408;
            }
          } else {
            if (!(data[7].missing != -1) || data[7].fvalue < 0.042994) {
              sum += (float)-0.0107892;
            } else {
              sum += (float)-0.0116848;
            }
          }
        } else {
          if (!(data[8].missing != -1) || data[8].fvalue < 7.60336e-10) {
            sum += (float)-0.0132545;
          } else {
            sum += (float)0.0342368;
          }
        }
      }
    }
  }
  if (!(data[10].missing != -1) || data[10].fvalue < 0.0187654) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.257373) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.254283) {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.164879) {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.200443) {
            if (!(data[43].missing != -1) || data[43].fvalue < 4.05396e-06) {
              sum += (float)-0.0083026;
            } else {
              sum += (float)-0.00783764;
            }
          } else {
            if (!(data[7].missing != -1) || data[7].fvalue < 0.0549793) {
              sum += (float)-0.00523247;
            } else {
              sum += (float)0.00479844;
            }
          }
        } else {
          if (!(data[13].missing != -1) || data[13].fvalue < 0.0640461) {
            if (!(data[13].missing != -1) || data[13].fvalue < 0.059711) {
              sum += (float)-0.00914381;
            } else {
              sum += (float)-0.000168702;
            }
          } else {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.339142) {
              sum += (float)0.0440544;
            } else {
              sum += (float)-0.0077085;
            }
          }
        }
      } else {
        sum += (float)0.0152008;
      }
    } else {
      if (!(data[26].missing != -1) || data[26].fvalue < 8.58835e-10) {
        if (!(data[8].missing != -1) || data[8].fvalue < 7.6574e-08) {
          if (!(data[35].missing != -1) || data[35].fvalue < 3.42725e-10) {
            sum += (float)-0.0172726;
          } else {
            sum += (float)-0.0102887;
          }
        } else {
          sum += (float)-0.00194136;
        }
      } else {
        sum += (float)-0.000107346;
      }
    }
  } else {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0603217) {
      if (!(data[37].missing != -1) || data[37].fvalue < 0.099957) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0105289) {
          sum += (float)-0.00837523;
        } else {
          sum += (float)-0.00890983;
        }
      } else {
        if (!(data[39].missing != -1) || data[39].fvalue < 0.00722077) {
          if (!(data[31].missing != -1) || data[31].fvalue < 5.18902e-05) {
            if (!(data[1].missing != -1) || data[1].fvalue < 2.59256e-06) {
              sum += (float)0.000970046;
            } else {
              sum += (float)-0.00558452;
            }
          } else {
            if (!(data[26].missing != -1) || data[26].fvalue < 9.41516e-05) {
              sum += (float)-0.00895863;
            } else {
              sum += (float)-0.00188784;
            }
          }
        } else {
          if (!(data[10].missing != -1) || data[10].fvalue < 0.0308392) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.00470426) {
              sum += (float)-0.00758065;
            } else {
              sum += (float)-0.00809786;
            }
          } else {
            if (!(data[17].missing != -1) || data[17].fvalue < 1.02923e-08) {
              sum += (float)-0.00743923;
            } else {
              sum += (float)-0.0051785;
            }
          }
        }
      }
    } else {
      if (!(data[43].missing != -1) || data[43].fvalue < 1.94795e-09) {
        if (!(data[10].missing != -1) || data[10].fvalue < 0.038874) {
          sum += (float)0.0281486;
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.168066) {
            sum += (float)0.00936499;
          } else {
            sum += (float)-0.00769939;
          }
        }
      } else {
        if (!(data[35].missing != -1) || data[35].fvalue < 1.8487e-09) {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.43987) {
            if (!(data[7].missing != -1) || data[7].fvalue < 0.386084) {
              sum += (float)-0.0105758;
            } else {
              sum += (float)-0.0048932;
            }
          } else {
            sum += (float)-0.00244312;
          }
        } else {
          if (!(data[35].missing != -1) || data[35].fvalue < 2.13795e-09) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0676503) {
              sum += (float)0.00220707;
            } else {
              sum += (float)0.0140261;
            }
          } else {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.179114) {
              sum += (float)-0.00754124;
            } else {
              sum += (float)0.000605643;
            }
          }
        }
      }
    }
  }
  if (!(data[1].missing != -1) || data[1].fvalue < 0.00544335) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0348535) {
      if (!(data[19].missing != -1) || data[19].fvalue < 0.105898) {
        if (!(data[35].missing != -1) || data[35].fvalue < 1.9558e-08) {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0982019) {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.0106863) {
              sum += (float)-0.00582345;
            } else {
              sum += (float)-0.00640121;
            }
          } else {
            if (!(data[20].missing != -1) || data[20].fvalue < 0.00957607) {
              sum += (float)-0.00492008;
            } else {
              sum += (float)-0.00581495;
            }
          }
        } else {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0780033) {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.00963365) {
              sum += (float)-0.00581986;
            } else {
              sum += (float)-0.00670891;
            }
          } else {
            if (!(data[33].missing != -1) || data[33].fvalue < 0.000240233) {
              sum += (float)0.00139926;
            } else {
              sum += (float)-0.00611784;
            }
          }
        }
      } else {
        if (!(data[7].missing != -1) || data[7].fvalue < 0.0454336) {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.202479) {
            sum += (float)0.033972;
          } else {
            if (!(data[26].missing != -1) || data[26].fvalue < 2.62687e-10) {
              sum += (float)0.00163381;
            } else {
              sum += (float)-0.0053461;
            }
          }
        } else {
          if (!(data[39].missing != -1) || data[39].fvalue < 0.0420943) {
            if (!(data[35].missing != -1) || data[35].fvalue < 2.08132e-09) {
              sum += (float)-0.00274554;
            } else {
              sum += (float)-0.00678407;
            }
          } else {
            if (!(data[7].missing != -1) || data[7].fvalue < 0.0618009) {
              sum += (float)0.00147374;
            } else {
              sum += (float)-0.00400941;
            }
          }
        }
      }
    } else {
      if (!(data[1].missing != -1) || data[1].fvalue < 0.0051364) {
        if (!(data[32].missing != -1) || data[32].fvalue < 6.96112e-06) {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.361845) {
            if (!(data[4].missing != -1) || data[4].fvalue < 0.000178696) {
              sum += (float)-0.000139214;
            } else {
              sum += (float)0.000564745;
            }
          } else {
            sum += (float)-0.00445592;
          }
        } else {
          if (!(data[31].missing != -1) || data[31].fvalue < 0.103526) {
            if (!(data[33].missing != -1) || data[33].fvalue < 0.00122018) {
              sum += (float)-0.00169703;
            } else {
              sum += (float)-0.00665852;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 1.71557e-09) {
              sum += (float)-0.00643142;
            } else {
              sum += (float)-0.00423842;
            }
          }
        }
      } else {
        if (!(data[33].missing != -1) || data[33].fvalue < 0.013562) {
          if (!(data[4].missing != -1) || data[4].fvalue < 0.0120422) {
            if (!(data[6].missing != -1) || data[6].fvalue < 0.0022462) {
              sum += (float)0.0287494;
            } else {
              sum += (float)-0.00502396;
            }
          } else {
            sum += (float)0.100405;
          }
        } else {
          if (!(data[4].missing != -1) || data[4].fvalue < 0.488598) {
            if (!(data[40].missing != -1) || data[40].fvalue < 0.00108754) {
              sum += (float)-0.000436633;
            } else {
              sum += (float)-0.00595741;
            }
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.248121) {
              sum += (float)0.00394419;
            } else {
              sum += (float)0.0207602;
            }
          }
        }
      }
    }
  } else {
    if (!(data[37].missing != -1) || data[37].fvalue < 0.100007) {
      if (!(data[10].missing != -1) || data[10].fvalue < 0.00617392) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0106245) {
          sum += (float)-0.00573157;
        } else {
          sum += (float)-0.00606232;
        }
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0107208) {
          sum += (float)-0.00599002;
        } else {
          sum += (float)-0.00622698;
        }
      }
    } else {
      if (!(data[19].missing != -1) || data[19].fvalue < 0.00531581) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0079971) {
          if (!(data[40].missing != -1) || data[40].fvalue < 0.160661) {
            if (!(data[23].missing != -1) || data[23].fvalue < 0.164548) {
              sum += (float)-0.00480322;
            } else {
              sum += (float)-0.00657127;
            }
          } else {
            if (!(data[4].missing != -1) || data[4].fvalue < 0.0552574) {
              sum += (float)-0.00413984;
            } else {
              sum += (float)-0.0022719;
            }
          }
        } else {
          if (!(data[39].missing != -1) || data[39].fvalue < 0.0348078) {
            if (!(data[19].missing != -1) || data[19].fvalue < 1.93803e-06) {
              sum += (float)-0.0081157;
            } else {
              sum += (float)-0.00592102;
            }
          } else {
            if (!(data[31].missing != -1) || data[31].fvalue < 0.0257127) {
              sum += (float)-0.000338139;
            } else {
              sum += (float)-0.00520295;
            }
          }
        }
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.033513) {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.07042e-10) {
            if (!(data[43].missing != -1) || data[43].fvalue < 1.97538e-10) {
              sum += (float)-0.00569752;
            } else {
              sum += (float)-0.00521419;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 1.16732e-09) {
              sum += (float)-0.00582428;
            } else {
              sum += (float)-0.00566997;
            }
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.0347452) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0346619) {
              sum += (float)0.00256058;
            } else {
              sum += (float)0.0658633;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 1.09341e-09) {
              sum += (float)-0.00218799;
            } else {
              sum += (float)-0.00593518;
            }
          }
        }
      }
    }
  }
  if (!(data[28].missing != -1) || data[28].fvalue < 0.274799) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0710465) {
      if (!(data[19].missing != -1) || data[19].fvalue < 0.0053632) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0106832) {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.0055735) {
            if (!(data[43].missing != -1) || data[43].fvalue < 9.85352e-09) {
              sum += (float)-0.0040517;
            } else {
              sum += (float)-0.00408548;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 2.09008e-09) {
              sum += (float)-0.00392693;
            } else {
              sum += (float)-0.00304414;
            }
          }
        } else {
          if (!(data[1].missing != -1) || data[1].fvalue < 0.0857909) {
            if (!(data[31].missing != -1) || data[31].fvalue < 0.000682861) {
              sum += (float)-0.00182516;
            } else {
              sum += (float)-0.00429393;
            }
          } else {
            sum += (float)0.0280923;
          }
        }
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.00285805) {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.099957) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.0160661) {
              sum += (float)-0.00407012;
            } else {
              sum += (float)-0.00433682;
            }
          } else {
            if (!(data[35].missing != -1) || data[35].fvalue < 3.41296e-10) {
              sum += (float)-0.00379047;
            } else {
              sum += (float)-0.00269454;
            }
          }
        } else {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0182278) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.0156795) {
              sum += (float)-0.00418844;
            } else {
              sum += (float)-0.0044224;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 1.48608e-08) {
              sum += (float)-0.00401666;
            } else {
              sum += (float)-0.00263205;
            }
          }
        }
      }
    } else {
      if (!(data[35].missing != -1) || data[35].fvalue < 2.03481e-10) {
        if (!(data[5].missing != -1) || data[5].fvalue < 0.000695702) {
          sum += (float)0.0332494;
        } else {
          if (!(data[26].missing != -1) || data[26].fvalue < 6.93352e-10) {
            sum += (float)0.00666368;
          } else {
            sum += (float)-0.00550278;
          }
        }
      } else {
        if (!(data[31].missing != -1) || data[31].fvalue < 0.223556) {
          if (!(data[5].missing != -1) || data[5].fvalue < 0.00184069) {
            if (!(data[5].missing != -1) || data[5].fvalue < 0.00175302) {
              sum += (float)-0.00262241;
            } else {
              sum += (float)0.0258911;
            }
          } else {
            if (!(data[35].missing != -1) || data[35].fvalue < 3.14457e-10) {
              sum += (float)-0.0091313;
            } else {
              sum += (float)-0.0045692;
            }
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.259948) {
            sum += (float)0.0199906;
          } else {
            sum += (float)-0.00156769;
          }
        }
      }
    }
  } else {
    if (!(data[26].missing != -1) || data[26].fvalue < 9.7956e-10) {
      if (!(data[35].missing != -1) || data[35].fvalue < 3.42725e-10) {
        if (!(data[1].missing != -1) || data[1].fvalue < 0.00268191) {
          sum += (float)-0.000651377;
        } else {
          if (!(data[8].missing != -1) || data[8].fvalue < 2.12264e-10) {
            sum += (float)-0.00238894;
          } else {
            sum += (float)-0.0122455;
          }
        }
      } else {
        if (!(data[8].missing != -1) || data[8].fvalue < 2.14596e-10) {
          sum += (float)-0.00230999;
        } else {
          sum += (float)-0.00670832;
        }
      }
    } else {
      if (!(data[0].missing != -1) || data[0].fvalue < 0.0365697) {
        sum += (float)0.00090753;
      } else {
        if (!(data[0].missing != -1) || data[0].fvalue < 0.1305) {
          sum += (float)-0.00178438;
        } else {
          sum += (float)-0.000446119;
        }
      }
    }
  }
  if (!(data[28].missing != -1) || data[28].fvalue < 0.274799) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0710465) {
      if (!(data[10].missing != -1) || data[10].fvalue < 0.0134691) {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.296247) {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.0107208) {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.00555281) {
              sum += (float)-0.00284963;
            } else {
              sum += (float)-0.00272114;
            }
          } else {
            if (!(data[17].missing != -1) || data[17].fvalue < 7.86745e-07) {
              sum += (float)-0.0029478;
            } else {
              sum += (float)-0.00123526;
            }
          }
        } else {
          if (!(data[8].missing != -1) || data[8].fvalue < 6.1e-10) {
            if (!(data[3].missing != -1) || data[3].fvalue < 3.5) {
              sum += (float)0.00107327;
            } else {
              sum += (float)-0.00303107;
            }
          } else {
            sum += (float)0.0239693;
          }
        }
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.0603217) {
          if (!(data[39].missing != -1) || data[39].fvalue < 0.00668318) {
            if (!(data[28].missing != -1) || data[28].fvalue < 0.00139946) {
              sum += (float)-0.0027995;
            } else {
              sum += (float)-0.0032462;
            }
          } else {
            if (!(data[15].missing != -1) || data[15].fvalue < 0.00453962) {
              sum += (float)0.0131655;
            } else {
              sum += (float)-0.00275036;
            }
          }
        } else {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.0134048) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.240902) {
              sum += (float)-0.00475089;
            } else {
              sum += (float)-1.03679e-05;
            }
          } else {
            if (!(data[1].missing != -1) || data[1].fvalue < 0.0335121) {
              sum += (float)0.0160794;
            } else {
              sum += (float)-0.0036694;
            }
          }
        }
      }
    } else {
      if (!(data[35].missing != -1) || data[35].fvalue < 2.03481e-10) {
        if (!(data[5].missing != -1) || data[5].fvalue < 0.000695702) {
          sum += (float)0.028262;
        } else {
          if (!(data[26].missing != -1) || data[26].fvalue < 6.93352e-10) {
            sum += (float)0.00516435;
          } else {
            sum += (float)-0.00426464;
          }
        }
      } else {
        if (!(data[31].missing != -1) || data[31].fvalue < 0.212043) {
          if (!(data[40].missing != -1) || data[40].fvalue < 0.00184081) {
            if (!(data[32].missing != -1) || data[32].fvalue < 0.0017531) {
              sum += (float)-0.00186665;
            } else {
              sum += (float)0.0220074;
            }
          } else {
            if (!(data[1].missing != -1) || data[1].fvalue < 0.0134048) {
              sum += (float)-0.00426475;
            } else {
              sum += (float)0.00171417;
            }
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.259948) {
            sum += (float)0.0159924;
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.268669) {
              sum += (float)-0.00133254;
            } else {
              sum += (float)0.00276532;
            }
          }
        }
      }
    }
  } else {
    if (!(data[26].missing != -1) || data[26].fvalue < 9.7956e-10) {
      if (!(data[35].missing != -1) || data[35].fvalue < 3.42725e-10) {
        if (!(data[1].missing != -1) || data[1].fvalue < 0.00268191) {
          sum += (float)-0.000553673;
        } else {
          if (!(data[8].missing != -1) || data[8].fvalue < 2.12264e-10) {
            sum += (float)-0.0020306;
          } else {
            sum += (float)-0.00898001;
          }
        }
      } else {
        if (!(data[43].missing != -1) || data[43].fvalue < 1.666e-08) {
          if (!(data[40].missing != -1) || data[40].fvalue < 0.0657192) {
            if (!(data[8].missing != -1) || data[8].fvalue < 2.14596e-10) {
              sum += (float)-0.00140018;
            } else {
              sum += (float)-0.00573992;
            }
          } else {
            sum += (float)-0.00182289;
          }
        } else {
          sum += (float)-0.00225634;
        }
      }
    } else {
      if (!(data[0].missing != -1) || data[0].fvalue < 0.0365697) {
        sum += (float)0.000771399;
      } else {
        if (!(data[0].missing != -1) || data[0].fvalue < 0.1305) {
          sum += (float)-0.00151673;
        } else {
          sum += (float)-0.000379207;
        }
      }
    }
  }
  if (!(data[30].missing != -1) || data[30].fvalue < 3.5) {
    if (!(data[1].missing != -1) || data[1].fvalue < 0.0710456) {
      if (!(data[38].missing != -1) || data[38].fvalue < 2.5) {
        if (!(data[43].missing != -1) || data[43].fvalue < 2.48075e-10) {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.48059e-10) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.484844) {
              sum += (float)-0.00192509;
            } else {
              sum += (float)-0.0015385;
            }
          } else {
            sum += (float)0.0805511;
          }
        } else {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.00266964) {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.099586) {
              sum += (float)-0.00199538;
            } else {
              sum += (float)-0.00171346;
            }
          } else {
            if (!(data[24].missing != -1) || data[24].fvalue < 3.96383e-05) {
              sum += (float)0.00286504;
            } else {
              sum += (float)-0.00205255;
            }
          }
        }
      } else {
        if (!(data[17].missing != -1) || data[17].fvalue < 0.000186705) {
          if (!(data[7].missing != -1) || data[7].fvalue < 0.594606) {
            if (!(data[8].missing != -1) || data[8].fvalue < 0.000105654) {
              sum += (float)-0.00201902;
            } else {
              sum += (float)0.00163514;
            }
          } else {
            if (!(data[40].missing != -1) || data[40].fvalue < 0.174611) {
              sum += (float)-0.00197836;
            } else {
              sum += (float)-0.00229869;
            }
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.271981) {
            sum += (float)-0.0012042;
          } else {
            sum += (float)0.0127082;
          }
        }
      }
    } else {
      if (!(data[0].missing != -1) || data[0].fvalue < 0.0353803) {
        if (!(data[0].missing != -1) || data[0].fvalue < 0.0353621) {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.034118) {
            sum += (float)0.00117575;
          } else {
            sum += (float)-0.00240497;
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.035371) {
            sum += (float)0.00652741;
          } else {
            sum += (float)0.0280677;
          }
        }
      } else {
        if (!(data[1].missing != -1) || data[1].fvalue < 0.0764085) {
          if (!(data[4].missing != -1) || data[4].fvalue < 0.0820272) {
            sum += (float)-0.0013817;
          } else {
            sum += (float)0.00425412;
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.439874) {
            if (!(data[38].missing != -1) || data[38].fvalue < 3.5) {
              sum += (float)-0.00278399;
            } else {
              sum += (float)-0.00122712;
            }
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.462362) {
              sum += (float)0.000150338;
            } else {
              sum += (float)-0.00109177;
            }
          }
        }
      }
    }
  } else {
    if (!(data[37].missing != -1) || data[37].fvalue < 0.0986735) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0054637) {
        if (!(data[10].missing != -1) || data[10].fvalue < 0.00617544) {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.00274653) {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.02924) {
              sum += (float)-0.00199585;
            } else {
              sum += (float)-0.00214232;
            }
          } else {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.0147889) {
              sum += (float)-0.00196546;
            } else {
              sum += (float)-0.00175862;
            }
          }
        } else {
          if (!(data[1].missing != -1) || data[1].fvalue < 0.01088) {
            sum += (float)-0.00218863;
          } else {
            sum += (float)-0.0020042;
          }
        }
      } else {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.00277951) {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.46637e-07) {
            if (!(data[19].missing != -1) || data[19].fvalue < 2.10166e-06) {
              sum += (float)-0.0026472;
            } else {
              sum += (float)-0.00233192;
            }
          } else {
            sum += (float)-0.00280238;
          }
        } else {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.0521995) {
            if (!(data[1].missing != -1) || data[1].fvalue < 0.00439052) {
              sum += (float)-0.00226181;
            } else {
              sum += (float)-0.002085;
            }
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0635594) {
              sum += (float)-0.00384917;
            } else {
              sum += (float)-0.000976057;
            }
          }
        }
      }
    } else {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0025894) {
        if (!(data[33].missing != -1) || data[33].fvalue < 0.000651753) {
          if (!(data[39].missing != -1) || data[39].fvalue < 0.00253597) {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.000879435) {
              sum += (float)-0.00290048;
            } else {
              sum += (float)0.00311285;
            }
          } else {
            if (!(data[8].missing != -1) || data[8].fvalue < 1.73077e-07) {
              sum += (float)0.0227791;
            } else {
              sum += (float)0.00615392;
            }
          }
        } else {
          if (!(data[35].missing != -1) || data[35].fvalue < 2.6825e-10) {
            if (!(data[32].missing != -1) || data[32].fvalue < 0.043736) {
              sum += (float)-0.00205874;
            } else {
              sum += (float)-0.000731696;
            }
          } else {
            if (!(data[7].missing != -1) || data[7].fvalue < 0.145637) {
              sum += (float)-0.00139238;
            } else {
              sum += (float)0.000143729;
            }
          }
        }
      } else {
        if (!(data[1].missing != -1) || data[1].fvalue < 1.19657e-06) {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.29224e-10) {
            if (!(data[9].missing != -1) || data[9].fvalue < 0.0354045) {
              sum += (float)0.0634487;
            } else {
              sum += (float)-0.000124525;
            }
          } else {
            if (!(data[35].missing != -1) || data[35].fvalue < 4.87489e-09) {
              sum += (float)-0.00179042;
            } else {
              sum += (float)0.0078861;
            }
          }
        } else {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.16016e-10) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.143432) {
              sum += (float)-0.0017804;
            } else {
              sum += (float)0.00733474;
            }
          } else {
            if (!(data[40].missing != -1) || data[40].fvalue < 0.346337) {
              sum += (float)-0.00200327;
            } else {
              sum += (float)-0.000398374;
            }
          }
        }
      }
    }
  }
  if (!(data[28].missing != -1) || data[28].fvalue < 0.274799) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.200443) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0321725) {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.0408417) {
          if (!(data[7].missing != -1) || data[7].fvalue < 0.908602) {
            if (!(data[10].missing != -1) || data[10].fvalue < 0.0131464) {
              sum += (float)-0.00139825;
            } else {
              sum += (float)-0.00134216;
            }
          } else {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.0858714) {
              sum += (float)-0.00143439;
            } else {
              sum += (float)9.09132e-05;
            }
          }
        } else {
          if (!(data[4].missing != -1) || data[4].fvalue < 0.0357362) {
            if (!(data[35].missing != -1) || data[35].fvalue < 9.13939e-09) {
              sum += (float)-0.00233388;
            } else {
              sum += (float)-0.000676142;
            }
          } else {
            if (!(data[4].missing != -1) || data[4].fvalue < 0.0368869) {
              sum += (float)0.0168427;
            } else {
              sum += (float)-0.000228941;
            }
          }
        }
      } else {
        if (!(data[9].missing != -1) || data[9].fvalue < 0.0363767) {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.038874) {
            if (!(data[8].missing != -1) || data[8].fvalue < 3.43244e-10) {
              sum += (float)0.0606595;
            } else {
              sum += (float)-0.00234063;
            }
          } else {
            if (!(data[17].missing != -1) || data[17].fvalue < 1.3601e-08) {
              sum += (float)-0.00202856;
            } else {
              sum += (float)0.00585452;
            }
          }
        } else {
          if (!(data[31].missing != -1) || data[31].fvalue < 0.139138) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.00951182) {
              sum += (float)-0.00147461;
            } else {
              sum += (float)-0.00237818;
            }
          } else {
            if (!(data[6].missing != -1) || data[6].fvalue < 0.121207) {
              sum += (float)0.0367364;
            } else {
              sum += (float)-0.000420268;
            }
          }
        }
      }
    } else {
      if (!(data[43].missing != -1) || data[43].fvalue < 5.96609e-09) {
        sum += (float)0.00824379;
      } else {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.23465) {
          sum += (float)0.00241545;
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.315038) {
            sum += (float)-0.00241475;
          } else {
            sum += (float)0.000441559;
          }
        }
      }
    }
  } else {
    if (!(data[26].missing != -1) || data[26].fvalue < 9.7956e-10) {
      if (!(data[37].missing != -1) || data[37].fvalue < 0.0500463) {
        sum += (float)-0.00173939;
      } else {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.0120643) {
          if (!(data[1].missing != -1) || data[1].fvalue < 0.00268191) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0369269) {
              sum += (float)-0.000170117;
            } else {
              sum += (float)-0.00170938;
            }
          } else {
            if (!(data[21].missing != -1) || data[21].fvalue < 5.5) {
              sum += (float)-0.00686533;
            } else {
              sum += (float)-0.00186171;
            }
          }
        } else {
          if (!(data[4].missing != -1) || data[4].fvalue < 0.0135066) {
            sum += (float)-0.000907101;
          } else {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.0482574) {
              sum += (float)-0.00133581;
            } else {
              sum += (float)-0.00425742;
            }
          }
        }
      }
    } else {
      if (!(data[0].missing != -1) || data[0].fvalue < 0.0365697) {
        sum += (float)0.000956185;
      } else {
        if (!(data[0].missing != -1) || data[0].fvalue < 0.1305) {
          sum += (float)-0.00098873;
        } else {
          sum += (float)-2.18293e-05;
        }
      }
    }
  }
  if (!(data[23].missing != -1) || data[23].fvalue < 0.00341437) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0321725) {
      if (!(data[39].missing != -1) || data[39].fvalue < 0.0298516) {
        if (!(data[1].missing != -1) || data[1].fvalue < 0.0184571) {
          if (!(data[28].missing != -1) || data[28].fvalue < 0.0160986) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.771105) {
              sum += (float)-0.000972956;
            } else {
              sum += (float)0.00140245;
            }
          } else {
            if (!(data[23].missing != -1) || data[23].fvalue < 0.00199848) {
              sum += (float)-0.00172409;
            } else {
              sum += (float)-0.000161791;
            }
          }
        } else {
          if (!(data[14].missing != -1) || data[14].fvalue < 0.00152939) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.0174263) {
              sum += (float)-0.00156759;
            } else {
              sum += (float)-0.00276753;
            }
          } else {
            if (!(data[22].missing != -1) || data[22].fvalue < 0.0108454) {
              sum += (float)-0.00167143;
            } else {
              sum += (float)-0.000965473;
            }
          }
        }
      } else {
        if (!(data[24].missing != -1) || data[24].fvalue < 0.0219338) {
          sum += (float)0.165301;
        } else {
          if (!(data[1].missing != -1) || data[1].fvalue < 1.30395e-06) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0351947) {
              sum += (float)0.0494873;
            } else {
              sum += (float)0.000569805;
            }
          } else {
            if (!(data[24].missing != -1) || data[24].fvalue < 0.0248251) {
              sum += (float)0.0130654;
            } else {
              sum += (float)-0.000933045;
            }
          }
        }
      }
    } else {
      if (!(data[43].missing != -1) || data[43].fvalue < 7.54787e-10) {
        if (!(data[1].missing != -1) || data[1].fvalue < 0.0174263) {
          if (!(data[43].missing != -1) || data[43].fvalue < 5.3817e-10) {
            if (!(data[6].missing != -1) || data[6].fvalue < 0.21584) {
              sum += (float)-0.00147975;
            } else {
              sum += (float)0.00178651;
            }
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.144326) {
              sum += (float)0.0006863;
            } else {
              sum += (float)0.00557783;
            }
          }
        } else {
          if (!(data[8].missing != -1) || data[8].fvalue < 9.45445e-10) {
            sum += (float)0.0529706;
          } else {
            sum += (float)-0.000614693;
          }
        }
      } else {
        if (!(data[39].missing != -1) || data[39].fvalue < 0.0190421) {
          if (!(data[4].missing != -1) || data[4].fvalue < 1.16045e-05) {
            sum += (float)-0.011183;
          } else {
            if (!(data[33].missing != -1) || data[33].fvalue < 0.00379021) {
              sum += (float)-0.000711399;
            } else {
              sum += (float)-0.00260876;
            }
          }
        } else {
          if (!(data[31].missing != -1) || data[31].fvalue < 0.0169377) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.036349) {
              sum += (float)0.0776319;
            } else {
              sum += (float)0.0152838;
            }
          } else {
            if (!(data[5].missing != -1) || data[5].fvalue < 0.00106693) {
              sum += (float)0.00120802;
            } else {
              sum += (float)-0.000960715;
            }
          }
        }
      }
    }
  } else {
    if (!(data[43].missing != -1) || data[43].fvalue < 4.05183e-06) {
      if (!(data[11].missing != -1) || data[11].fvalue < 0.090451) {
        if (!(data[19].missing != -1) || data[19].fvalue < 0.00276509) {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.00262983) {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.0999115) {
              sum += (float)-0.000978285;
            } else {
              sum += (float)-0.00046702;
            }
          } else {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.0762345) {
              sum += (float)-0.000947596;
            } else {
              sum += (float)-0.00122814;
            }
          }
        } else {
          if (!(data[31].missing != -1) || data[31].fvalue < 0.0586672) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.0124827) {
              sum += (float)-0.000778458;
            } else {
              sum += (float)-0.00110771;
            }
          } else {
            if (!(data[22].missing != -1) || data[22].fvalue < 0.000630324) {
              sum += (float)0.00604332;
            } else {
              sum += (float)-0.000477731;
            }
          }
        }
      } else {
        if (!(data[10].missing != -1) || data[10].fvalue < 0.00270882) {
          if (!(data[37].missing != -1) || data[37].fvalue < 0.0617344) {
            sum += (float)-0.000951917;
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 4.38225e-07) {
              sum += (float)-0.00131401;
            } else {
              sum += (float)-0.00212352;
            }
          }
        } else {
          if (!(data[19].missing != -1) || data[19].fvalue < 2.03007e-06) {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.029896) {
              sum += (float)-0.00107482;
            } else {
              sum += (float)-0.00206572;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 1.15647e-09) {
              sum += (float)-0.00100791;
            } else {
              sum += (float)-0.000918479;
            }
          }
        }
      }
    } else {
      if (!(data[37].missing != -1) || data[37].fvalue < 0.0852534) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.00269831) {
          sum += (float)-0.00111344;
        } else {
          sum += (float)-0.00139087;
        }
      } else {
        if (!(data[39].missing != -1) || data[39].fvalue < 0.000418324) {
          if (!(data[19].missing != -1) || data[19].fvalue < 2.10166e-06) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.0639821) {
              sum += (float)-0.00109357;
            } else {
              sum += (float)-0.00297817;
            }
          } else {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.000204371) {
              sum += (float)-0.00168789;
            } else {
              sum += (float)-0.000966041;
            }
          }
        } else {
          if (!(data[43].missing != -1) || data[43].fvalue < 4.20847e-06) {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.162771) {
              sum += (float)0.0100306;
            } else {
              sum += (float)0.00351547;
            }
          } else {
            if (!(data[31].missing != -1) || data[31].fvalue < 0.0097711) {
              sum += (float)-0.000296379;
            } else {
              sum += (float)0.00115531;
            }
          }
        }
      }
    }
  }
  if (!(data[28].missing != -1) || data[28].fvalue < 0.274799) {
    if (!(data[28].missing != -1) || data[28].fvalue < 0.0710465) {
      if (!(data[28].missing != -1) || data[28].fvalue < 0.0106776) {
        if (!(data[28].missing != -1) || data[28].fvalue < 0.00557568) {
          if (!(data[19].missing != -1) || data[19].fvalue < 0.0429972) {
            if (!(data[19].missing != -1) || data[19].fvalue < 0.00809382) {
              sum += (float)-0.000685272;
            } else {
              sum += (float)-0.000581773;
            }
          } else {
            if (!(data[1].missing != -1) || data[1].fvalue < 0.00938338) {
              sum += (float)-0.00126237;
            } else {
              sum += (float)-0.00227068;
            }
          }
        } else {
          if (!(data[43].missing != -1) || data[43].fvalue < 2.08005e-09) {
            if (!(data[19].missing != -1) || data[19].fvalue < 1.67213e-06) {
              sum += (float)-0.00222599;
            } else {
              sum += (float)-0.000599411;
            }
          } else {
            if (!(data[37].missing != -1) || data[37].fvalue < 0.0990351) {
              sum += (float)-0.00110061;
            } else {
              sum += (float)0.000689364;
            }
          }
        }
      } else {
        if (!(data[41].missing != -1) || data[41].fvalue < 0.00170317) {
          if (!(data[43].missing != -1) || data[43].fvalue < 4.3514e-10) {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.00142673) {
              sum += (float)-0.00164364;
            } else {
              sum += (float)0.00106342;
            }
          } else {
            if (!(data[4].missing != -1) || data[4].fvalue < 1.15371e-05) {
              sum += (float)-0.00950555;
            } else {
              sum += (float)-0.00292079;
            }
          }
        } else {
          if (!(data[33].missing != -1) || data[33].fvalue < 0.00164828) {
            if (!(data[41].missing != -1) || data[41].fvalue < 0.0040297) {
              sum += (float)0.00366439;
            } else {
              sum += (float)0.0242369;
            }
          } else {
            if (!(data[19].missing != -1) || data[19].fvalue < 2.10166e-06) {
              sum += (float)-0.00191232;
            } else {
              sum += (float)-0.000720072;
            }
          }
        }
      }
    } else {
      if (!(data[35].missing != -1) || data[35].fvalue < 2.00432e-10) {
        if (!(data[5].missing != -1) || data[5].fvalue < 0.000695702) {
          sum += (float)0.0243632;
        } else {
          if (!(data[7].missing != -1) || data[7].fvalue < 0.129834) {
            if (!(data[3].missing != -1) || data[3].fvalue < 4.5) {
              sum += (float)-0.000222602;
            } else {
              sum += (float)-0.00282681;
            }
          } else {
            sum += (float)0.00453587;
          }
        }
      } else {
        if (!(data[31].missing != -1) || data[31].fvalue < 0.212043) {
          if (!(data[33].missing != -1) || data[33].fvalue < 0.00394663) {
            if (!(data[39].missing != -1) || data[39].fvalue < 0.00469717) {
              sum += (float)-0.00169598;
            } else {
              sum += (float)0.00675931;
            }
          } else {
            if (!(data[43].missing != -1) || data[43].fvalue < 4.17863e-09) {
              sum += (float)-0.00180128;
            } else {
              sum += (float)0.00143661;
            }
          }
        } else {
          if (!(data[0].missing != -1) || data[0].fvalue < 0.259948) {
            sum += (float)0.0134715;
          } else {
            if (!(data[0].missing != -1) || data[0].fvalue < 0.268669) {
              sum += (float)-0.000625022;
            } else {
              sum += (float)0.00285922;
            }
          }
        }
      }
    }
  } else {
    if (!(data[40].missing != -1) || data[40].fvalue < 0.00103189) {
      if (!(data[7].missing != -1) || data[7].fvalue < 0.0474957) {
        if (!(data[0].missing != -1) || data[0].fvalue < 0.0347623) {
          sum += (float)-0.00150646;
        } else {
          sum += (float)-0.00032581;
        }
      } else {
        sum += (float)-0.004936;
      }
    } else {
      if (!(data[1].missing != -1) || data[1].fvalue < 0.0308311) {
        if (!(data[7].missing != -1) || data[7].fvalue < 0.0472339) {
          if (!(data[4].missing != -1) || data[4].fvalue < 0.0469923) {
            sum += (float)-0.00275727;
          } else {
            sum += (float)-0.000696316;
          }
        } else {
          if (!(data[26].missing != -1) || data[26].fvalue < 8.58835e-10) {
            if (!(data[22].missing != -1) || data[22].fvalue < 0.0417256) {
              sum += (float)-0.00064501;
            } else {
              sum += (float)-0.00149715;
            }
          } else {
            sum += (float)0.000504732;
          }
        }
      } else {
        sum += (float)-0.00491099;
      }
    }
  }
  return sum + (2);
}
