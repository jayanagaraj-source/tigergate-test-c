terraform {
  required_version = ">= 1.0"
  required_providers {
    # Deliberately old provider versions for SCA scanner testing.
    aws = {
      source  = "hashicorp/aws"
      version = "3.0.0"
    }
    random = {
      source  = "hashicorp/random"
      version = "2.2.0"
    }
  }
}
