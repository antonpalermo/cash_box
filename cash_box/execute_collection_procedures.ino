
void execute_collection_procedures(int red, int green, int blue) {
  Serial.println("[process]: executing collection procedures...");
  delay(1000);
  Serial.print("[process]: RGB value: ");

  Serial.print(red);
  Serial.print(", ");
  Serial.print(green);
  Serial.print(", ");
  Serial.print(blue);

  Serial.println("");

  // delay(2000);
  // Serial.println("[info]: ammount pressent: ***This should be the ammount taken by the color sensor***");
  // delay(1000);
  // Serial.println("[info]: await collection approval...");
  // delay(1000);
  // Serial.println("[process]: approved storing ***amount captured*** ");
  delay(2000);
  Serial.println("[info]: collection procedures complete...");
}