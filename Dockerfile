# Deliberately insecure container fixture for image + Dockerfile scanners.
# DL3006/DL3007: base image pinned to a known-old tag on purpose (SCA/CVE).
FROM node:16.14.0-buster

# DL3002: running as root (no USER directive switches away)
# Hard-coded secret baked into an ENV layer (visible in image history).
ENV DATABASE_PASSWORD="otDzZxIZV0TxcDMdva6cZ4ld" \
    AWS_SECRET_ACCESS_KEY="2RGW9oG7BEwcswP0G9DMm88yREgec+bZ4ay0Dim0" \
    APP_ENV=production

WORKDIR /app

# DL3008: apt-get without version pins; DL3009: apt lists not cleaned;
# curl | sh pattern for a remote installer (supply-chain smell).
RUN apt-get update && apt-get install -y curl netcat sudo \
    && curl -sL https://example.com/install.sh | sh

COPY . .

# DL3016/DL3018: install without lockfile enforcement
RUN npm install --unsafe-perm

# DL3025: shell-form CMD; app listens on all interfaces
EXPOSE 3000
CMD node server.js --host 0.0.0.0
