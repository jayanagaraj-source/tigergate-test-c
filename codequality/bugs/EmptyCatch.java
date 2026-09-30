// RULE: empty-catch (MEDIUM) | lang: java
import java.io.IOException;
public class EmptyCatch{
  void risky(){
    try{ doThing(); }
    catch(IOException e){ /* empty catch: swallowed */ }
  }
  void doThing() throws IOException {}
}
