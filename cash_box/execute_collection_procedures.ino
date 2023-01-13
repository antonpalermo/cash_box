/**
This function should handle color sensor reading and storing of amount.
*/
void execute_collection_procedures() {
  Serial.println("[process]: executing collection procedures...");
  delay(1000);
  Serial.println("[process]: looking for color patterns...");
  delay(2000);
  Serial.println("[info]: ammount pressent: ***This should be the ammount taken by the color sensor***");
  delay(1000);
  Serial.println("[info]: await collection approval...");
  delay(1000);
  Serial.println("[process]: approved storing ***amount captured*** ");
  delay(2000);
  Serial.println("[info]: collection procedures complete...");
}