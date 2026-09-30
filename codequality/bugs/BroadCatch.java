// RULE: broad-catch (MEDIUM) | lang: java
public class BroadCatch{
  void risky(){
    try{ doThing(); }
    catch(Exception e){ log(e); } // overly broad exception handler
  }
  void doThing() throws Exception {}
  void log(Exception e){ System.out.println(e); }
}
