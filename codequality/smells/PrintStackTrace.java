// RULE: print-stack-trace (LOW) | lang: java
public class PrintStackTrace{
  void run(){
    try{ work(); }
    catch(Exception e){ e.printStackTrace(); } // stack trace printed instead of logged
  }
  void work() throws Exception {}
}
