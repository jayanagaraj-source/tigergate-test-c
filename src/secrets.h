/*
 * Hard-coded credential fixtures for secret-scanner validation.
 *
 * SAFETY: every value below is SYNTHETIC. The tokens are randomly generated to
 * match each provider's format so shape/entropy detectors fire, but they
 * authenticate to nothing. The RSA key is a throwaway generated for this
 * fixture and secures nothing. Do NOT reuse any of this.
 */
#ifndef TIGERGATE_SECRETS_H
#define TIGERGATE_SECRETS_H

/* CWE-798: hard-coded credentials */
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "password123"

/* AWS: high-entropy synthetic pair (detectable). */
#define AWS_ACCESS_KEY_ID     "AKIAHEV1VKDKVWH24XBJ"
#define AWS_SECRET_ACCESS_KEY "2RGW9oG7BEwcswP0G9DMm88yREgec+bZ4ay0Dim0"
/* AWS documented example pair (usually allowlisted; kept to test allowlisting). */
#define AWS_ACCESS_KEY_ID_EXAMPLE "AKIAIOSFODNN7EXAMPLE"

/* GitHub personal access token (classic ghp_ + 36) */
#define GITHUB_TOKEN "ghp_Ow1aNd8q7N8L5jgn8w0sZWYwsOuaP3bBmbqA"
/* GitHub fine-grained PAT */
#define GITHUB_FINEGRAINED_PAT "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"

/* Slack bot token */
#define SLACK_BOT_TOKEN "xoxb-303343674632-345460097915-qj2n64l2LOuvWxDhpyqz5fUZ"

/* Stripe live secret key */
#define STRIPE_SECRET_KEY "sk_live_hYQhiTV8vl4Up0pn2Ck0Vp0N"

/* Google API key */
#define GOOGLE_API_KEY "AIzar02bdd1BXW361BxtomKyw7zimlbPnNkoLR9"

/* Twilio API key SID (SK + 32 hex) */
#define TWILIO_API_KEY "SK79e11e727cefa901428ce964f47799bd"

/* SendGrid API key */
#define SENDGRID_API_KEY "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"

/* npm access token */
#define NPM_TOKEN "npm_e4N9nmWXEJfey4lO1I6geLIxaZ6ck7RM0ou6"

/* Generic high-entropy API token + hex secret */
#define GENERIC_API_TOKEN "sopbWjaxmuRPa1U5XvsVQ60QV0Jzh9Tyyrb6qYH9uQi0drmv"
#define HEX_SECRET "cb95e7a6427be07f6ae36afd1dc300d1583e9440e58ce809be60b8dbb67961a9"

/* Connection strings with embedded high-entropy passwords (CWE-259) */
#define DATABASE_URL "postgres://app:otDzZxIZV0TxcDMdva6cZ4ld@db.internal:5432/tigergate"
#define MONGO_URL    "mongodb://root:uieky4trqENQJlVtLzvVs2eE@mongo.internal:27017/admin"
#define REDIS_URL    "redis://:NYOydybbFFfRNuvFeNDZRzuh@cache.internal:6379/0"

/* Symmetric key + IV baked into the binary (CWE-321) */
#define XOR_KEY "tigergate-static-key-0000"
#define AES_KEY "00112233445566778899aabbccddeeff00112233445566778899aabbccddeeff"
#define AES_IV  "0123456789abcdef"

/* JWT signing secret + a signed HS256 token (CWE-321) */
#define JWT_SECRET "A4MIEKNklMHF8nphXxxHdyKFcDt_gpUdNX6yaJ8As7H1mPmJthZsT_AOqWcN7RYr"
#define JWT_TOKEN  "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiJ0aWdlcmdhdGUtZml4dHVyZSIsInJvbGUiOiJhZG1pbiIsImlhdCI6MTcwMDAwMDAwMH0.hthVnAMWlfgcPZxZ99b2bfj5hw2HouTVj0z6-MURtpM"

#endif /* TIGERGATE_SECRETS_H */
