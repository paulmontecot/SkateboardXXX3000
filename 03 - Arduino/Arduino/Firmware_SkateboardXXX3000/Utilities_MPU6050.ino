void printMovuinoData() {
  Serial.print(ax / float(32768));
  Serial.print("\t ");
  Serial.print(ay / float(32768));
  Serial.print("\t ");
  Serial.print(az / float(32768));
  Serial.print("\t ");
  Serial.print(gx / float(32768));
  Serial.print("\t ");
  Serial.print(gy / float(32768));
  Serial.print("\t ");
  Serial.print(gz / float(32768));
  Serial.print("\t ");
  Serial.print(mx);
  Serial.print("\t ");
  Serial.print(my);
  Serial.print("\t ");
  Serial.print(mz);
  Serial.println();
}
void writeInFileMovuinoData(File file, String sep) {
  file.print(ax / float(32768));
  file.print(sep);
  file.print(ay / float(32768));
  file.print(sep);
  file.print(az / float(32768));
  file.print(sep);
  file.print(gx / float(32768));
  file.print(sep);
  file.print(gy / float(32768));
  file.print(sep);
  file.print(gz / float(32768));
  file.print(sep);
  file.print(mx);
  file.print(sep);
  file.print(my);
  file.print(sep);
  file.print(mz);
  file.println();
}
void initialiseFileMovuinoData(File file, String sep) {
  file.print("ax");
  file.print(sep);
  file.print("ay");
  file.print(sep);
  file.print("az");
  file.print(sep);
  file.print("gx");
  file.print(sep);
  file.print("gy");
  file.print(sep);
  file.print("gz");
  file.print(sep);
  file.print("mx");
  file.print(sep);
  file.print("my");
  file.print(sep);
  file.print("mz");
  file.println();
}

void magnetometerAutoCallibration() {
  int magVal[] = {mx, my, mz};
  for (int i = 0; i < 3; i++) {
    // Compute magnetometer range
    if (magVal[i] < magRange[2 * i]) {
      magRange[2 * i] = magVal[i]; // update minimum values on each axis
    }
    if (magVal[i] > magRange[2 * i + 1]) {
      magRange[2 * i + 1] = magVal[i]; // update maximum values on each axis
    }

    // Scale magnetometer values
    if (magRange[2 * i] != magRange[2 * i + 1]) {
      magVal[i] = map(magVal[i], magRange[2 * i], magRange[2 * i + 1], -100, 100);
    }
  }

  // Update magnetometer values
  mx = magVal[0];
  my = magVal[1];
  mz = magVal[2];
}
