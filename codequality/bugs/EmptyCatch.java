// RULE: empty-catch | lang: java — empty catch (specific + generic)
import java.io.IOException;
public class EmptyCatch {
  void risky() {
    try { doThing(); } catch (IOException e) {}
    try { doThing(); } catch (Exception e) {}
  }
  void doThing() throws IOException {}
}
